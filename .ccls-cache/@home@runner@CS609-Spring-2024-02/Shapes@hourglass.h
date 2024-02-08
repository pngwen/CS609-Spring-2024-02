///////////////////////////////////////////////////////////////////////////
// File: hourglass.h
// Purpose: A drawable which draws an hour glass
// Author: Robert Lowe < rlowe@semo.edu >
///////////////////////////////////////////////////////////////////////////
#include "drawable.h"

class Hourglass : public Drawable {
public:
  // Constructor
  // Parameters:
  //   x - x-coordinate of the upper left corner of the hour glass
  //   y - y-coordinate of the upper left corner of the hour glass
  //   w - width of the hour glass
  //   h - height of the hour glass
  Hourglass(int _x, int _y, int _w, int _h);

  // Draw the hour glass
  virtual void draw(Canvas* canvas);

private:
  int _x;
  int _y;
  int _w;
  int _h;
};