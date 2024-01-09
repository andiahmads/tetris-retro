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
