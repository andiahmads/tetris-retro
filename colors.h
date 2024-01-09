#pragma once

#include <raylib.h>
#include <vector>
using namespace std;

// extern digunakan untuk mendeklarasikan variabel dalam satu file dan
// menggunakannya di file lain.
extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;

vector<Color> GetCellColors();
