#pragma once
#include "blocks.cpp"
#include "grid.h"
#include <block.h>
#include <vector>
using namespace std;

class Game {
public:
  // constructr
  Game();

  // gambar permainan
  void Draw();

  // memindahkan posisi block
  void HandleInput();

  Grid grid;

private:
  // deteksi perpindahan block ke kiri
  void MoveBlockLeft();
  // deteksi perpindahan block ke kekanan
  void MoveBlockRight();
  // deteksi perpindahan block ke kebawah
  void MoveBlockDown();

  // mengambil kembali seluruh block
  vector<Block> GetAllBlock();

  // return random block
  Block GetRandomBlock();

  // memeriksa apakah sebuah block berada diluar jendela
  // permainan.
  bool IsBlockOutside();

  // abstraksi dari class block.h, berfungsi untuk rotasi block
  void RotateBlock();
  vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
};
