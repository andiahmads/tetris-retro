#include "game.h"
#include "raylib.h"
#include <algorithm>
#include <iostream>
#include <position.h>
#include <random>
#include <vector>
using namespace std;

Game::Game() {
  grid = Grid();
  blocks = GetAllBlock();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock() {

  // jika block kosong
  if (blocks.empty()) {
    // isi kembali block
    blocks = GetAllBlock();
  }

  // untuk mendapatkan nilai acak dari 0-6, dan digunakan untuk mengindeks
  // vektor blok.
  int randomIndex = rand() % blocks.size();

  // acak kemunculan block
  Block block = blocks[randomIndex];

  // menghapus  index dari vektor sehingga tidak terjadi duplikat
  // kemunculan block saat dipanggil
  blocks.erase(blocks.begin() + randomIndex);

  return block;
}

vector<Block> Game::GetAllBlock() {
  return {
      IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock(),
  };
}

void Game::Draw() {
  grid.Draw();
  // grid.Print();
  currentBlock.Draw();
}

void Game::HandleInput() {
  // identifikasi key yang ditekan oleh pengguna
  int keyPressed = GetKeyPressed();
  switch (keyPressed) {
  case KEY_LEFT:
    MoveBlockLeft();
    break;
  case KEY_RIGHT:
    MoveBlockRight();
    break;
  case KEY_DOWN:
    MoveBlockDown();
    break;
  }
}

void Game::MoveBlockLeft() {
  // jika keluar dari cell kiri, kembalikan lagi ke posisi column 1
  cout << "keluar " << IsBlockOutside() << endl;
  currentBlock.Move(0, -1);

  if (IsBlockOutside()) {
    currentBlock.Move(0, 1);
  }
}

void Game::MoveBlockRight() {

  currentBlock.Move(0, 1);

  if (IsBlockOutside()) {
    currentBlock.Move(0, -1);
  }
}

void Game::MoveBlockDown() {
  currentBlock.Move(1, 0);
  if (IsBlockOutside()) {
    currentBlock.Move(-1, 0);
  }
}

bool Game::IsBlockOutside() {
  // ambil posisi block
  vector<Position> tiles = currentBlock.GetCellPosition();

  for (Position item : tiles) {
    if (grid.IsCellOutSide(item.row, item.column)) {
      return true;
    }
  }
  return false;
}
