#include "drawable.h"

class Triangle : public Drawable {
public:
  // Constructor
  // Parameters:
  //   x1, y1 - coordinates of the first vertex of the triangle
  //   x2, y2 - coordinates of the second vertex of the triangle
  //   x3, y3 - coordinates of the third vertex of the triangle
  Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

  // Draw the triangle
  virtual void draw(Canvas *canvas);

private:
  int _x1, _y1; // Coordinates of the first vertex
  int _x2, _y2; // Coordinates of the second vertex
  int _x3, _y3; // Coordinates of the third vertex

  // Helper method to draw a line between two points
  void drawLine(Canvas *canvas, int x1, int y1, int x2, int y2);
};