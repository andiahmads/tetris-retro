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
  void Draw();
  int id; // representasi dari sel yang ditempati oleh block dalam grid 4x4
          // untuk semua rotasi
  map<int, vector<Position>>
      cells; // atribut ini akan menjadai peta vektor yang akan
             // menampung setiap cell yang ditempati

  // memindahkan posisi block
  void Move(int rows, int columns);

  // menghitung posisi sebenarnya dari setiap cell.
  // mengembalikan sel yang ditempati dengan offset yang diterapkan dalam
  // vektor.
  vector<Position> GetCellPosition();

private:
  int cellSize;      // mengetahui ukuran setiap cell block dalam pixel
  int rotationState; // keadaan rotasi block saat ini
  vector<Color> colors;
  int rowOffset;    // memindahkan block kekanan == x
  int columnOffset; // memindahkan block kebawah == y
};
