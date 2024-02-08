///////////////////////////////////////////////////////////////////////////
// File: circle.cpp
// Purpose: A drawable which draws a circle
// Authors: Tyler Blankenship  < tbblankenship1s@semo.edu >, Venkata Ravindra 
//<vsiddavatam1s@semo.edu>,Sreenivasulu Ramanaboina sramanaboina1s@semo.edu >
//<sghosh3s@semo.edu>, Saurav Ghosh
//<msomepalli1s@semo.edu>, Manikumar Somepalli
//<vtalla1s@semo.edu>, Vijaya Narasimha Reddy Talla
//<asaleheen1s@semo.edu>, Abrar Saleheen
//vevani1s@semo.edu, sai revanth evani
//kyeddanapudi1s@semo.edu, Kusuma Sri Yeddanapudi >
//<nkollu1s@semo.edu>, Naresh Kollu
//<jlunavath1s@gmail.com>, Jeesha Lunavath 
//<lzhang4s@semo.edu>add names here
//
/////////////////////////////////////////////////////////////////////////

#include "drawable.h"
#include "canvas.h"
#include "circle.h"
#include "cmath"

Circle::Circle(int _x, int _y, int _r) {
  this->_x = _x;
  this->_y = _y;
  this->_r = _r;
}

void Circle::draw(Canvas* canvas) {

  //circle drawing logic
  for (int i = 0; i < 360; ++i) {
      int xPos = _x + static_cast<int>(_r * std::cos(i * 3.14 / 180.0));
      int yPos = _y + static_cast<int>(_r * std::sin(i * 3.14 / 180.0));
      canvas->point(xPos, yPos);
      }
} 