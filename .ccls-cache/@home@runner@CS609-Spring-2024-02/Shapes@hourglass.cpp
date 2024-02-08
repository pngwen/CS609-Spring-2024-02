///////////////////////////////////////////////////////////////////////////
// File: hourglass.h
// Purpose: A drawable which draws an hour glass
// Author: Robert Lowe < rlowe@semo.edu >
///////////////////////////////////////////////////////////////////////////
#include "drawable.h"
#include "canvas.h"
#include "hourglass.h"

Hourglass::Hourglass(int _x, int _y, int _w, int _h) {
  this->_x = _x;
  this->_y = _y;
  this->_w = _w;
  this->_h = _h;
}


void Hourglass::draw(Canvas* canvas) {
  //compute the other extremes
  int rx = _x + _w;
  int ly = _y + _h;

  //draw the shape
  canvas->line(_x, _y, rx, _y); //top line
  canvas->line(_x, ly, rx, ly); //bottom line
  canvas->line(_x, _y, rx, ly); //diagonal 1
  canvas->line(rx, _y, _x, ly); //diagonal 2
}