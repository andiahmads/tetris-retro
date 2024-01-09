#pragma once
#include "blocks.cpp"
#include "grid.h"
#include <block.h>
#include <vector>
using namespace std;

class Game {
public:
  // constructro
  Game();

  // return random block
  Block GetRandomBlock();

  // mengambil kembali seluruh block
  vector<Block> GetAllBlock();

  // gambar permainan
  void Draw();

  // memindahkan posisi block
  void HandleInput();

  // deteksi perpindahan block ke kiri
  void MoveBlockLeft();
  // deteksi perpindahan block ke kekanan
  void MoveBlockRight();
  // deteksi perpindahan block ke kebawah
  void MoveBlockDown();

  Grid grid;

private:
  // memeriksa apakah sebuah block berada diluar jendela
  // permainan.
  bool IsBlockOutside();
  vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
};
