///////////////////////////////////////////////////////////////////////////
// File: canvas.h
// Purpose: Class definition for a simple canvas that operates on drawables
// Author: Robert Lowe < rlowe@semo.edu >
///////////////////////////////////////////////////////////////////////////
#ifndef CANVAS_H
#define CANVAS_H
//#include <SDL.h>
#include <string>
#include <vector>

// Class prototype for external class
class Drawable;

class Canvas {
public:
  // Constructors
  Canvas(const std::string &title, int width, int height);
  Canvas(int width, int height);
  Canvas();

  //////////////////////////////////////////
  // Drawing functions
  //////////////////////////////////////////

  // Draw a point on the canvas
  // Parameters:
  //   x: x-coordinate of the point
  //   y: y-coordinate of the point
  virtual void point(int x, int y);

  // Draw a line on the canvas from (x1,y1) to (x2,y2))
  // Parameters:
  //   x1: x-coordinate of the first point
  //   y1: y-coordinate of the first point
  //   x2: x-coordinate of the second point
  //   y2: y-coordinate of the second point
  virtual void line(int x1, int y1, int x2, int y2);

  // Sets the drawing color
  // Parameters:
  //   r: red component of the color (0-255)
  //   g: green component of the color (0-255)
  //   b: blue component of the color (0-255)
  virtual void color(int r, int g, int b);

  // Render Loop
  virtual void render_loop();

  // Return the width of the canvas
  virtual int width();

  // Return the height of the canvas
  virtual int height();

  //////////////////////////////////////////
  // container Functions
  //////////////////////////////////////////

  // Add a drawable object to the canvas
  // Parameters:
  //   d: pointer to the drawable object
  virtual void add(Drawable *d);

  // Clears all Drawable objects from the canvas
  virtual void clear();

  // Returns a const iterator to the beginning of the canvas's drawables
  virtual std::vector<Drawable *>::const_iterator begin() const;

  // Returns a const iterator to the end of the canvas's drawables
  virtual std::vector<Drawable *>::const_iterator end() const;

private:
  // Drawable objects
  std::vector<Drawable *> _drawables;

  // Low level graphics objects
  
























































SDL_Window *_window;
  SDL_Renderer *_renderer;
};
#endif