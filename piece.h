#ifndef MYFILE_H_
#define MYFILE_H_

#include <vector>
#include <string>
using namespace std;

// your code goes here
class Tetromino {
  public:
    vector<vector<int> > coordinates;
    int orientation;
    vector<int> bottomLeftMostCord;
    vector<int> centerCoord;
    const vector<vector<vector<int> > > orientations;
    string symbol;
    string color;

    void rotate(bool clockwise) {
      if (clockwise) {
        orientation++;
      } else {
        orientation--;
      }
    }

    vector<vector<int> > getPieceOrientation() {
      return orientations[orientation];
    }
};

class TPiece: public Tetromino {
  public:
    string symbol = "T";
    string color = "purple";

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
    string symbol = "S";
    string color = "green";

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
    string symbol = "Z";
    string color = "red";

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
    string symbol = "I";
    string color = "cyan";

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
    string symbol = "L";
    string color = "orange";

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
    string symbol = "J";
    string color = "blue";

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
    string symbol = "O";
    string color = "yellow";

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

#endif
