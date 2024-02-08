///////////////////////////////////////////////////////////////////////////
// File: static.h
// Purpose: Draw a field of static to test out the drawable interface
// Author: Robert Lowe <rlowe@semo.edu>
///////////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include "static.h"
#include "canvas.h"  


// Implement the draw method from Drawable
void Static::draw(Canvas *canvas) {
  int w = canvas->width();
  int h = canvas->height();

  for(int x = 0; x < w; x++) {
    for(int y = 0; y < h; y++) {
      //randomly set the color to either black or white
      if(rand() % 2 == 0) {
        canvas->color(0, 0, 0);
      } else {
        canvas->color(255, 255, 255);
      }

      // draw the point
      canvas->point(x, y);
    }
  }
}