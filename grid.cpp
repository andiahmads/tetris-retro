#include "grid.h"
#include "colors.h"
#include <iostream>
#include <raylib.h>
#include <vector>
using namespace std;

Grid::Grid() {
  numRows = 20;
  numCols = 10;
  cellSize = 30;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numCols; column++) {
      // mencetak angka disemua cell
      grid[row][column] = 0;
    }
  }
}

void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numCols; column++) {
      cout << grid[row][column] << " ";
    }
    cout << endl;
  }
}

void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numCols; column++) {
      int cellValue = grid[row][column];
      DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutSide(int row, int column) {
  // jika posisi baris dan kolom berada dalam grid, maka return false
  if (row >= 0 && row < numRows && column >= 0 && column < numCols) {
    return false;
  }
  return true;
}

bool Grid::IsCellEmpty(int row, int column) {
  // check ketika memindahkan block satu baris kebawah kita perlu memastikan
  // apakah sel-sel grid yang ditempati block tersebut kosong atau tidak
  // jika tidak kosong, kita harus membatalkan perpindahan dan mengunci block
  // pada tempatnya.
  if (grid[row][column] == 0) {
    return true;
  }
  return false;
}

bool Grid::IsRowFull(int row) {
  // mendapatkan setiap kolom grid
  for (int column = 0; column < numCols; column++) {
    // periksa apakah nilai selnya 0
    if (grid[row][column] == 0) {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row) {
  // mendapatkan setiap kolom grid
  for (int column = 0; column < numCols; column++) {
    // set row, dan column menjadi 0
    grid[row][column] = 0;
  }
}

void Grid::MoveRowDown(int row, int numRows) {

  for (int column = 0; column < numCols; column++) {
    // mengubah nilai baris tujuan agar sama dengan baris saat ini.
    grid[row + numRows][column] = grid[row][column];

    // hapus baris saat ini
    grid[row][column] = 0;
  }
}

int Grid::ClearFullRows() {
  int completed = 0;
  // memeriksa setiap baris mulai dari 19 dan turun kebaris 0;
  for (int row = numRows - 1; row >= 0; row--) {

    // memeriksa apakah baris aat ini sudah penuh dengan menggunakan metod
    // is_row_full.
    if (IsRowFull(row)) {
      // menghapus semua sel dibaris saat ini.
      ClearRow(row);

      // tambahakan 1 untuk melacak jumlah baris yang telah selesai.
      completed++;
    }
    // jika baris saat ini belum penuh, tetapi beberapa baris sudah dihapus,
    // maka pindahkan kebawah
    else if (completed > 0) {
      MoveRowDown(row, completed);
    }
  }

  // kembalikan baris yang sudah selesai
  return completed;
}
