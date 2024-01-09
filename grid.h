#pragma once // menghindari definisi duplikat
#include <raylib.h>
#include <vector>
using namespace std;

class Grid {
public:
  // Constructor
  Grid();
  void Initialize();
  int grid[20][10]; // sebuah array 2 dimensi untuk membuat jaringan pada game
                    // tetris
  void Draw();      // mengambar grid
  bool IsCellOutSide(int row,
                     int col); // check apakah posisi block keluar dari cell

  void Print(); // debuging

private:
  int numRows;          // jumlah rows
  int numCols;          // cols
  int cellSize;         // ukuran cell
  vector<Color> colors; // warna dari tetrimino
};
