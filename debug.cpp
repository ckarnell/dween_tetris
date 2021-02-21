/* NOTE TO SELF: Run with `g++ -std=c++11 -o debugprog debug.cpp && ./debugprog` */
#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
#include <random>
#include "piece.h"
using namespace std;

int main()
{
  IPiece *myPiece = new IPiece;
  /* cout << to_string(myPiece -> getPieceOrientation(0)[1][1]); */
  
  /* cout << to_string(myPiece -> orientations[0][1][1]); */
  /* cout << myPiece.orientations[0].size() << endl; */
  for (int x = 0; x < 4; x++) {
    vector<vector<int> > currentPieceOrientations = myPiece -> getPieceOrientation(x);
    for (int j = 0; j < currentPieceOrientations.size(); j++) {
      for (int k = 0; k < currentPieceOrientations[j].size(); k++) {
        cout << currentPieceOrientations[j][k];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
