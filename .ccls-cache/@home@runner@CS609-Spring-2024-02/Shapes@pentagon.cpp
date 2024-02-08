#include "pentagon.h"
#include "canvas.h"
#include "cmath"
#include "drawable.h"

Pentagon::Pentagon(int _x, int _y, int _side) {
  this->_x = _x;
  this->_y = _y;
  this->_side = _side;
}

void Pentagon::draw(Canvas *canvas) {

  // Pentagon drawing logic
  for (int i = 0; i < 5; ++i) {
    int xPos = _x + static_cast<int>(_side * std::cos(i * 2 * 3.14 / 5));
    int yPos = _y + static_cast<int>(_side * std::sin(i * 2 * 3.14 / 5));
    canvas->point(xPos, yPos);
  }
}
