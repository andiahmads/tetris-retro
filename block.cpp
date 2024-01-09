#include "block.h"
#include "raylib.h"
#include <colors.h>
#include <iostream>
#include <position.h>
#include <vector>

Block::Block() {
  cellSize = 30;
  rotationState = 0;
  colors = GetCellColors();
  rowOffset = 0;
  columnOffset = 0;
}

void Block::Draw() {
  vector<Position> tiles = GetCellPosition(); // rotasi saat ini adalah 0
  // gambar
  for (Position item : tiles) {
    DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1,
                  cellSize - 1, cellSize - 1, colors[id]);
  }
}

void Block::Move(int rows, int columns) {
  // tambahkan setiap object dengan param
  rowOffset += rows;
  columnOffset += columns;
}

vector<Position> Block::GetCellPosition() {
  // ambil posisi cell defaul
  vector<Position> tiles = cells[rotationState];

  // vektor kosong barus untuk menampung block yang dipindahkan.
  vector<Position> movedTiles;

  // mengulang semua block dan menambahkan setiap offset ke posisi aslinya.
  for (Position item : tiles) {
    Position newPos =
        Position(item.row + rowOffset, item.column + columnOffset);

    // append ke vektor movedTiles;
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}

void Block::Rotate() {
  rotationState++;

  // check apakah jumlah rotasi melebihi batas rotasi
  if (rotationState == (int)cells.size()) {
    rotationState = 0;
  }
}

void Block::UndoRotation() {
  // atur rotasi blok ke sebelumnya
  rotationState--;
  if (rotationState == -1) {
    rotationState = cells.size() - 1;
  }
}
