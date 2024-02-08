///////////////////////////////////////////////////////////////////////////
// File: circle.h
// Purpose: A drawable which draws a circle
// Authors: Tyler Blankenship  < tbblankenship1s@semo.edu >, Venkata Ravindra
//srahman5s@semo.edu>
// <vsiddavatam1s@semo.edu>, Sreenivasulu Ramaboina sramanaboina1s@semo.edu
//<kyeddanapudi1s@semo.edu>,kusumasri yeddanapudi
//<btekmal1s@semo.edu>,Bal Ram Reddy Tekmal
//<sghosh3s@semo.edu>, Saurav Ghosh
//<asaleheen1s@semo.edu>, Abrar Saleheen
//<pthota1s@semo.edu>, Pavan Thota
//<mgummula1s@semo.edu/ Mahesh Gummula
//<nkollu1s@semo.edu>,Naresh Kollu
//<jlunavath1s@semo.edu>, Jeesha Lunavath 
//<chavarohith1s@semo.edu>, Chavarohi//////////////////////

#include "drawable.h"

class Circle : public Drawable {
public:
  // Constructor
  // Parameters:
  //   x - x-coordinate of the center of the circle
  //   y - y-coordinate of the center of the circle
  //   r - radius of the circle
  Circle(int _x, int _y, int _r);

  // Draw the circle
  virtual void draw(Canvas* canvas);

private:
  int _x;
  int _y;
  int _r;
};