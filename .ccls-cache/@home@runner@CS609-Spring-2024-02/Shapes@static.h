///////////////////////////////////////////////////////////////////////////
// File: static.h
// Purpose: Draw a field of static to test out the drawable interface
// Author: Robert Lowe <rlowe@semo.edu>
///////////////////////////////////////////////////////////////////////////
#ifndef STATIC_H
#define STATIC_H
#include "drawable.h"

class Static : public Drawable {
public:
  void draw(Canvas *canvas);
};

#endif