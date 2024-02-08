#include "canvas.h"
#include "rectangle.h"  // Assuming you have a Rectangle class

int main(int argc, char *argv[]) {
  Canvas canvas; // Create a default canvas
  Rectangle *rectangle;

  // create a rectangle
  rectangle = new Rectangle(100, 100, 50, 50); // create a rectangle

  // add the rectangle to the canvas and render it
  canvas.add(rectangle);
  canvas.render_loop();

  // destroy  the rectangle
  delete rectangle;

  return 0;
}
