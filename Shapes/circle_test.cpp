
///////////////////////////////////////////////////////////////////////////
// File: circle_test.cpp
// Purpose: Program to draw a circle
// Authors: Tyler Blankenship  < tbblankenship1s@semo.edu >, Venkata Ravindra
//srahman5s@semo.edu> 
// <vsiddavatam1s@semo.edu>, Sreenivasulu Ramaboina sramanaboina1s@semo.edu
//<kyeddanapudi1s@semo.edu>,kusumasri yeddanapudi
//<btekmal1s@semo.edu>,Bal Ram Reddy Tekmal
//<sghosh3s@semo.edu>, Saurav Ghosh
//<asaleheen1s@semo.edu>, Abrar Saleheen
//<pthota1s@semo.edu>, Pavan Thota
//<mgummula1s@semo.edu>, Mahesh Gummula
/////////////////////////////////////////////////////////////////////////

#include "canvas.h"
#include "circle.h"

int main(int argc, char *argv[]) {
  Canvas canvas;
  Circle *circle;

  // create the circle
  circle = new Circle(320, 240, 100);

  // add the circle to the canvas and render it
  canvas.add(circle);
  canvas.render_loop();

  // destroy the circle
  delete circle;

  return 0;
}