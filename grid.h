#pragma once // menghindari definisi duplikat
#include <raylib.h>
#include <vector>
using namespace std;

class Grid {
public:
  // Constructor
  Grid();
  // init cell
  void Initialize();

  // sebuah array 2 dimensi untuk membuat jaringan pada game tetris
  int grid[20][10];

  // mengambar grid
  void Draw();

  // check apakah posisi block keluar dari cell
  bool IsCellOutSide(int row, int col);

  // digunakan untuk memastikan tidak terjadi saling tabrakan antar block
  bool IsCellEmpty(int row, int column);

  // debuging
  void Print();

  // clear seluruh rows, metode ini akan memeriksa semua baris dari bawah
  // keatas untuk memeriksa apakah ada baris yang selesai.
  int ClearFullRows();

private:
  // memeriksa apakah suatu baris sudah penuh.
  bool IsRowFull(int row);

  // menghapus sebuah baris -> ex: jika semuah row dan cell penuh.
  void ClearRow(int row);

  // memindahkan baris kebawah sebanyak jumlah baris tertentu.
  void MoveRowDown(int row, int numRows);

  int numRows;          // jumlah rows
  int numCols;          // cols
  int cellSize;         // ukuran cell
  vector<Color> colors; // warna dari tetrimino
};
