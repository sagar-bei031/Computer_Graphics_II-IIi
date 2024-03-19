#pragma once

#include <SDL2/SDL.h>

namespace CSA
{
// Define region codes for the Cohen-Sutherland algorithm
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Calculate region code for a point (x, y)
int calculateCode(int x, int y, int x_min, int x_max, int y_min, int y_max);

bool clipLine(int &x1, int &y1, int &x2, int &y2, int x_min, int x_max, int y_min, int y_max);
} // namespace CSA

namespace LBA
{
bool clipLine(int &x1, int &y1, int &x2, int &y2, int x_min, int x_max, int y_min, int y_max);
};