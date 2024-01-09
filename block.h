#pragma once
#include "colors.h"
#include "position.h"
#include <map>
#include <vector>

using namespace std;

class Block {
public:
  // constructor
  Block();

  // gambar block
  void Draw();

  // representasi dari sel yang ditempati oleh block dalam grid 4x4
  // untuk semua rotasi
  int id;

  // atribut ini akan menjadai peta vektor yang akan menampung setiap cell yang
  // ditempati
  map<int, vector<Position>> cells;

  // memindahkan posisi block
  void Move(int rows, int columns);

  // menghitung posisi sebenarnya dari setiap cell.
  // mengembalikan sel yang ditempati dengan offset yang diterapkan dalam
  // vektor.
  vector<Position> GetCellPosition();

  // rotasi block
  void Rotate();

  // undo rotasi block
  // method ini digunakan untuk case, ketika posisi rotasi berada di ujung
  // row/column, maka ketika di rotasi, cell block tersebut menjadi terpotong
  void UndoRotation();

private:
  int cellSize;      // mengetahui ukuran setiap cell block dalam pixel
  int rotationState; // keadaan rotasi block saat ini
  vector<Color> colors;
  int rowOffset;    // memindahkan block kekanan == x
  int columnOffset; // memindahkan block kebawah == y
};
