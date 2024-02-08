#include "canvas.h"
#include "hourglass.h"

int main(int argc, char *argv[]) {
  Canvas canvas; // Create a default canvas
  Hourglass *glass;

  // create the hourglass
  glass = new Hourglass(300, 40, 40, 40); // create an hourglass

  // add the hourglass to the canvas and render it
  canvas.add(glass);
  canvas.render_loop();

  // destroy the hourglass
  delete glass;

  return 0;
}  
