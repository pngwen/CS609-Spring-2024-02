///////////////////////////////////////////////////////////////////////////
// File: drawable.h
// Purpose: Drawable interface
// Author: Robert Lowe
///////////////////////////////////////////////////////////////////////////
#ifndef DRAWABLE_H
#define DRAWABLE_H

// Prototype for external class
class Canvas;

// Interface for drawing
class Drawable {
public:
  // Draw the object
  // Parameters:
  //   canvas - the canvas to draw on
  virtual void draw(Canvas *canvas) = 0;

  // Virtual Destructor
  virtual ~Drawable();
};

#endif