#ifndef MYFILE_H_
#define MYFILE_H_

#include <vector>
#include <string>
using namespace std;

// your code goes here
class Tetromino {
  public:
    vector<vector<int> > coordinates;
    int orientation = 0;
    vector<int> bottomLeftMostCord;
    vector<int> centerCoord;
    const vector<vector<vector<int> > > orientations;
    wstring symbol;
    string color;

    virtual void rotate(bool clockwise) {
      if (clockwise) {
        orientation++;
      } else {
        orientation--;
      }
    }

    virtual vector<vector<int> > getPieceOrientation(int orientation) {
      return orientations[orientation];
    }
};

class TPiece: public Tetromino {
  public:
    wstring symbol = L"T";
    string color = "purple";

    vector<vector<int> > getPieceOrientation(int orientation) {
      return orientations[orientation];
    }

    const vector<vector<vector<int> > > orientations = {
      {
          { 0, 0, 0, 0 },
          { 0, 1, 0, 0 },
          { 1, 1, 1, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 1, 0 },
          { 0, 1, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 0, 0, 0 },
          { 1, 1, 1, 0 },
          { 0, 1, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 0, 0 },
          { 1, 1, 0, 0 },
          { 0, 1, 0, 0 }
      }
    };
};

class SPiece: public Tetromino {
  public:
    wstring symbol = L"S";
    string color = "green";

    vector<vector<int> > getPieceOrientation(int orientation) {
      return orientations[orientation];
    }

    const vector<vector<vector<int> > > orientations = {
      {
          { 0, 0, 0, 0 },
          { 0, 1, 1, 0 },
          { 1, 1, 0, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 1, 0 },
          { 0, 0, 1, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 0, 0, 0 },
          { 0, 1, 1, 0 },
          { 1, 1, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 1, 0, 0, 0 },
          { 1, 1, 0, 0 },
          { 0, 1, 0, 0 }
      }
    };
};

class ZPiece: public Tetromino {
  public:
    wstring symbol = L"Z";
    string color = "red";

    vector<vector<int> > getPieceOrientation(int orientation) {
      return orientations[orientation];
    }

    const vector<vector<vector<int> > > orientations = {
      {
          { 0, 0, 0, 0 },
          { 1, 1, 0, 0 },
          { 0, 1, 1, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 0, 1, 0 },
          { 0, 1, 1, 0 },
          { 0, 1, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 0, 0, 0 },
          { 1, 1, 0, 0 },
          { 0, 1, 1, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 0, 0 },
          { 1, 1, 0, 0 },
          { 1, 0, 0, 0 }
      }
    };
};

class IPiece: public Tetromino {
  public:
    wstring symbol = L"I";
    string color = "cyan";

    vector<vector<int> > getPieceOrientation(int orientation) {
      return orientations[orientation];
    }

    const vector<vector<vector<int> > > orientations = {
      {
          { 0, 0, 0, 0 },
          { 1, 1, 1, 1 },
          { 0, 0, 0, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 1, 0 },
          { 0, 0, 1, 0 },
          { 0, 0, 1, 0 },
          { 0, 0, 1, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 0, 0, 0 },
          { 1, 1, 1, 1 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 1, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 0, 0 }
      }
    };
};

class LPiece: public Tetromino {
  public:
    wstring symbol = L"L";
    string color = "orange";

    vector<vector<int> > getPieceOrientation(int orientation) {
      return orientations[orientation];
    }

    const vector<vector<vector<int> > > orientations = {
      {
          { 0, 0, 0, 0 },
          { 0, 0, 1, 0 },
          { 1, 1, 1, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 1, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 0, 0, 0 },
          { 1, 1, 1, 0 },
          { 1, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 1, 1, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 0, 0 }
      },
    };
};

class JPiece: public Tetromino {
  public:
    wstring symbol = L"J";
    string color = "blue";

    vector<vector<int> > getPieceOrientation(int orientation) {
      return orientations[orientation];
    }

    const vector<vector<vector<int> > > orientations = {
      {
          { 0, 0, 0, 0 },
          { 1, 0, 0, 0 },
          { 1, 1, 1, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 1, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 0, 0, 0 },
          { 1, 1, 1, 0 },
          { 0, 0, 1, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 1, 0, 0 },
          { 1, 1, 0, 0 }
      },
    };
};

class OPiece: public Tetromino {
  public:
    wstring symbol = L"O";
    string color = "yellow";

    vector<vector<int> > getPieceOrientation(int orientation) {
      return orientations[orientation];
    }

    const vector<vector<vector<int> > > orientations = {
      {
          { 0, 0, 0, 0 },
          { 0, 1, 1, 0 },
          { 0, 1, 1, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 1, 0 },
          { 0, 1, 1, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 1, 0 },
          { 0, 1, 1, 0 },
          { 0, 0, 0, 0 }
      },
      {
          { 0, 0, 0, 0 },
          { 0, 1, 1, 0 },
          { 0, 1, 1, 0 },
          { 0, 0, 0, 0 }
      }
    };
};

class PieceBag {
  public:
    IPiece iPiece = IPiece();
    TPiece tPiece = TPiece();
    JPiece jPiece = JPiece();
    LPiece lPiece = LPiece();
    OPiece oPiece = OPiece();
    SPiece sPiece = SPiece();
    ZPiece zPiece = ZPiece();

    template <typename T>
    T getPiece(int index) {
      switch (index) {
        case 0 :
          return iPiece;
        case 1 :
          return tPiece;
        case 2 :
          return jPiece;
        case 3 :
          return lPiece;
        case 4 :
          return oPiece;
        case 5 :
          return sPiece;
        case 6 :
          return zPiece;
        /* TPiece tPiece = TPiece(); */
        /* JPiece jPiece = JPiece(); */
        /* LPiece lPiece = LPiece(); */
        /* OPiece oPiece = OPiece(); */
        /* SPiece sPiece = SPiece(); */
        /* ZPiece zPiece = ZPiece(); */
      }
      return iPiece;
    }
};


#endif
