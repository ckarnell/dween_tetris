/* NOTE TO SELF: Run with `g++ -std=c++11 -o tetrisprog tetris.cpp && ./tetrisprog` */
/* Compile with debugger with `g++ -std=c++11 -g -o tetrisprog tetris.cpp` */
/* Debug with `sudo gdb ./tetrisprog` */
/*
	OneLoneCoder.com - Command Line Tetris
	"Put Your Money Where Your Mouth Is" - @Javidx9
	
	License
	~~~~~~~
	Copyright (C) 2018  Javidx9
	This program comes with ABSOLUTELY NO WARRANTY.
	This is free software, and you are welcome to redistribute it
	under certain conditions; See license for details. 
	Original works located at:
	https://www.github.com/onelonecoder
	https://www.onelonecoder.com
	https://www.youtube.com/javidx9

	GNU GPLv3
	https://github.com/OneLoneCoder/videos/blob/master/LICENSE

	From Javidx9 :)
	~~~~~~~~~~~~~~~
	Hello! Ultimately I don't care what you use this for. It's intended to be 
	educational, and perhaps to the oddly minded - a little bit of fun. 
	Please hack this, change it and use it in any way you see fit. You acknowledge 
	that I am not responsible for anything bad that happens as a result of 
	your actions. However this code is protected by GNU GPLv3, see the license in the
	github repo. This means you must attribute me if you use it. You can view this
	license here: https://github.com/OneLoneCoder/videos/blob/master/LICENSE
	Cheers!
	
	Background
	~~~~~~~~~~
	I made a video "8-Bits of advice for new programmers" (https://youtu.be/vVRCJ52g5m4)
	and suggested that building a tetris clone instead of Dark Sould IV might be a better 
	approach to learning to code. Tetris is nice as it makes you think about algorithms. 
	
	Controls are Arrow keys Left, Right & Down. Use Z to rotate the piece. 
	You score 25pts per tetronimo, and 2^(number of lines)*100 when you get lines.
	
	Future Modifications
	~~~~~~~~~~~~~~~~~~~~
	1) Show next block and line counter
	
	Author
	~~~~~~
	Twitter: @javidx9
	Blog: www.onelonecoder.com
	
	Video:
	~~~~~~
	https://youtu.be/8OK8_tHeCIA
	
	Last Updated: 30/03/2017
*/

#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
#include <random>
#include "piece.h"
/* #include <Carbon/Carbon.h> */
using namespace std;

#include <stdio.h>
/* #include <Windows.h> */

int nScreenWidth = 80;			// Console Screen Size X (columns)
int nScreenHeight = 30;			// Console Screen Size Y (rows)
/* typedef std::shared_ptr<Tetromino> TetrominoPtr; */
vector<Tetromino*> tetromino;
int nFieldWidth = 10 + 2; // 10 + 2 for the sides
int nFieldHeight = 20 + 1; // 20, + 1 for the bottom border
unsigned char *pField = nullptr;

wstring getStringFromPieceOrientationVector(vector<vector<int> > pieceOrientationVector)
{
  wstring result = L"";
  for (int i=0; i < pieceOrientationVector.size(); i++)
  {
    for (int j=0; j < pieceOrientationVector[i].size(); j++)
    {
      int currentPixle = pieceOrientationVector[i][j];
      if (currentPixle == 0) {
        wstring nextChar = L".";
        result.push_back(nextChar[0]);
      } else {
        wstring nextChar = L"X";
        result.push_back(nextChar[0]);
      }
    }
  }
  return result;
}

/* Boolean isPressed( unsigned short inKeyCode ) */
/* { */
/*     unsigned char keyMap[16]; */
/*     GetKeys((BigEndianUInt32*) &keyMap); */
/*     return (0 != ((keyMap[ inKeyCode >> 3] >> (inKeyCode & 7)) & 1)); */
/* } */

int Rotate(int px, int py, int r)
{
	int pi = 0;
	switch (r % 4)
	{
	case 0: // 0 degrees			  //  0  1  2  3
		pi = py * 4 + px;			    //  4  5  6  7
		break;						        //  8  9 10 11
									            // 12 13 14 15

	case 1: // 90 degrees			  // 12  8  4  0
		pi = 12 + py - (px * 4);	// 13  9  5  1
		break;						        // 14 10  6  2
									            // 15 11  7  3

	case 2: // 180 degrees			//15 14 13 12
		pi = 15 - (py * 4) - px;	//11 10  9  8
		break;						        // 7  6  5  4
									            // 3  2  1  0

	case 3: // 270 degrees			// 3  7 11 15
		pi = 3 - py + (px * 4);		// 2  6 10 14
		break;						        // 1  5  9 13
	}								            // 0  4  8 12

	return pi;
}

bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY)
{
	// All Field cells >0 are occupied
	for (int px = 0; px < 4; px++)
		for (int py = 0; py < 4; py++)
		{
			// Get index into piece
      int pi = py * 4 + px;	//  TODO: Does this work?
			/* int pi = Rotate(px, py, nRotation); */

			// Get index into field
			int fi = (nPosY + py) * nFieldWidth + (nPosX + px);

			// Check that test is in bounds. Note out of bounds does
			// not necessarily mean a fail, as the long vertical piece
			// can have cells that lie outside the boundary, so we'll
			// just ignore them
			if (nPosX + px >= 0 && nPosX + px < nFieldWidth)
			{
				if (nPosY + py >= 0 && nPosY + py < nFieldHeight)
				{
					// In Bounds so do collision check
          /* if (tetromino[nTetromino][pi] != L'.' && pField[fi] != 0) */
          wstring currentString = getStringFromPieceOrientationVector(tetromino[nTetromino] -> getPieceOrientation(nRotation));
					if (currentString[pi] != L'.' && pField[fi] != 0)
						return false; // fail on first hit
				}
			}
		}

	return true;
}

int myrandom (int i) { return std::rand()%i;}

vector<int> CreateNewBag() 
{
  int arr[] = {0, 1, 2, 3, 4, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  /* vector<int> orderedBag{0, 1, 2, 3, 4, 5, 6}; */
  vector<int> orderedBag(arr, arr + n);
  /* orderedBag = [0, 1, 2, 3, 4, 5, 6]; */
  std::random_shuffle (orderedBag.begin(), orderedBag.end(), myrandom);
  return orderedBag;
}


int main()
{
	// Create Screen Buffer
	wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
  // TODO: Replace or remove these
	/* HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); */
	/* SetConsoleActiveScreenBuffer(hConsole); */
	/* DWORD dwBytesWritten = 0; */
	
  // Tetronimos 4x4
	tetromino.push_back(new TPiece);
	tetromino.push_back(new SPiece);
	tetromino.push_back(new ZPiece);
	tetromino.push_back(new JPiece);
	tetromino.push_back(new LPiece);
	tetromino.push_back(new IPiece);
	tetromino.push_back(new OPiece);

	pField = new unsigned char[nFieldWidth*nFieldHeight]; // Create play field buffer
	for (int x = 0; x < nFieldWidth; x++) // Board Boundary
		for (int y = 0; y < nFieldHeight; y++)
			pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;

  // Seed randomness based on current time
  srand (time(NULL));

	// Game Logic
	bool bKey[4];
	int nCurrentRotation = 0;
	int nCurrentX = (nFieldWidth / 2) - 2; // Subtract 2 to offset piece width, which is 4
	int nCurrentY = 0 - 1;
	int nSpeed = 20;
	int nSpeedCount = 0;
	bool bForceDown = false;
	bool bRotateHold = true;
	int nPieceCount = 0;
	int nScore = 0;
	int currentBagIndex = 0;
	vector<int> vLines;
	bool bGameOver = false;

  // This next line seems necessary to "kick off" actual randomness,
  // otherwise the first piece is always the same. Very weird.
  myrandom(7);

  // Create the ordering of the first set of 7 pieces.
  vector<int> pieceBag = CreateNewBag();
  int nCurrentPiece = pieceBag[currentBagIndex];

	while (!bGameOver) // Main Loop
	{

		// Timing =======================
		/* this_thread::sleep_for(50ms); // Small Step = 1 Game Tick */
		nSpeedCount++;
		bForceDown = (nSpeedCount == nSpeed);

		// Input ========================
    /* char inputVar; */
		for (int k = 0; k < 4; k++)								// R   L   D Z
    {
      // TODO: Implement user input
      /* cin >> inputVar; */
      /* cout << inputVar; */
			/* bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0; */
    }
		
		// Game Logic ===================

		// Handle player movement
		nCurrentX += (bKey[0] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0;
		nCurrentX -= (bKey[1] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY)) ? 1 : 0;		
		nCurrentY += (bKey[2] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) ? 1 : 0;

		// Rotate, but latch to stop wild spinning
		if (bKey[3])
		{
			nCurrentRotation += (bRotateHold && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 : 0;
			bRotateHold = false;
		}
		else
			bRotateHold = true;

		// Force the piece down the playfield if it's time
		if (bForceDown)
		{
			// Update difficulty every 50 pieces
			nSpeedCount = 0;
			nPieceCount++;
			if (nPieceCount % 50 == 0)
				if (nSpeed >= 10) nSpeed--;
			
			// Test if piece can be moved down
			if (DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
				nCurrentY++; // It can, so do it!
			else
			{
				// It can't! Lock the piece in place
				for (int px = 0; px < 4; px++)
					for (int py = 0; py < 4; py++)
          {
            int pi = py * 4 + px;	//  TODO: Does this work?
						/* if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] != L'.') */
						if (getStringFromPieceOrientationVector(tetromino[nCurrentPiece] -> getPieceOrientation(nCurrentRotation))[pi] != L'.')
            {
							pField[(nCurrentY + py) * nFieldWidth + (nCurrentX + px)] = nCurrentPiece + 1;
            }
          }

				// Check for lines
				for (int py = 0; py < 4; py++)
					if(nCurrentY + py < nFieldHeight - 1)
					{
						bool bLine = true;
						for (int px = 1; px < nFieldWidth - 1; px++)
							bLine &= (pField[(nCurrentY + py) * nFieldWidth + px]) != 0;

						if (bLine)
						{
							// Remove Line, set to =
							for (int px = 1; px < nFieldWidth - 1; px++)
								pField[(nCurrentY + py) * nFieldWidth + px] = 8;
							vLines.push_back(nCurrentY + py);
						}						
					}

				nScore += 25;
				if(!vLines.empty())	nScore += (1 << vLines.size()) * 100;

				// Pick New Piece
				nCurrentX = nFieldWidth / 2 - 2; // Subtract 2 to offset piece width, which is 4
				nCurrentY = 0 - 1;
				nCurrentRotation = 0;

        currentBagIndex++;
        if (currentBagIndex == 7) {
          currentBagIndex = 0;
          pieceBag = CreateNewBag();
        }
				nCurrentPiece = pieceBag[currentBagIndex];

				// If piece does not fit straight away, game over!
				bGameOver = !DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY);
			}
		}

		// Display ======================

		// Draw Field
		for (int x = 0; x < nFieldWidth; x++)
			for (int y = 0; y < nFieldHeight; y++)
				screen[(y + 2)*nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y*nFieldWidth + x]];

		// Draw Current Piece
		for (int px = 0; px < 4; px++)
			for (int py = 0; py < 4; py++)
      {
        int pi = py * 4 + px;	//  TODO: Does this work?
        Tetromino* currentPiece = tetromino[nCurrentPiece];
        vector<vector<int>  > currentPieceOrientation = currentPiece -> getPieceOrientation(nCurrentRotation);
        /* cout << "HOW WE HERE?" << endl; */
        /* for (int j = 0; j < currentPieceOrientations.size(); j++) { */
        /*   for (int k = 0; k < currentPieceOrientations[j].size(); k++) { */
        /*     cout << currentPieceOrientations[j][k]; */
        /*   } */
        /*   cout << endl; */
        /* } */
        /* print(currentPieceOrientations) */
        /* cout << currentPieceOrientations */





        /* vector<vector<int> > currentPieceOrientation = currentPieceOrientations[nCurrentRotation]; */






        wstring stringFromPieceOrientationVector = getStringFromPieceOrientationVector(currentPieceOrientation);





				if (stringFromPieceOrientationVector[pi] != L'.')
        {
          screen[(nCurrentY + py + 2)*nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;
        }
      }

		// Draw Score
    // TODO: Remove or replace write function
		/* swprintf_s(&screen[2 * nScreenWidth + nFieldWidth + 6], 16, L"SCORE: %8d", nScore); */

		// Animate Line Completion
		if (!vLines.empty())
		{
			// Display Frame (cheekily to draw lines)
      // TODO: Remove or replace write function
			/* WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten); */
			/* this_thread::sleep_for(400ms); // Delay a bit */

			for (auto &v : vLines)
				for (int px = 1; px < nFieldWidth - 1; px++)
				{
					for (int py = v; py > 0; py--)
						pField[py * nFieldWidth + px] = pField[(py - 1) * nFieldWidth + px];
					pField[px] = 0;
				}

			vLines.clear();
		}

		// Display Frame
    // TODO: Remove or replace write function
		/* WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten); */
    /* wcout << screen << endl; */
    /* wprintf (screen); */
    /* bGameOver = true; */
    /* cout << @"\x1bc"; */
    /* cout << '\033c'; */
    for (long i = 0; i < nScreenWidth * nScreenHeight; i++) {
      if (i % nScreenWidth == 0) {
        cout << endl;
      }
      wcout << (screen[i]);
    }
    cout << endl << endl<< endl<< endl<< endl<< endl<< endl<< endl;

    for (long i = 999999; i > 0; i--) {
      // Fake ass way of delaying timing
    }
    /* for (int i = screen - 1; i >= 0; i--) */ 
    /*   cout << array[i]; */

	}

	// Oh Dear
  // TODO: Remove or replace the next line
	/* CloseHandle(hConsole); */
	cout << "Game Over!! Score:" << nScore << endl;
	/* system("pause"); */
	return 0;
}

