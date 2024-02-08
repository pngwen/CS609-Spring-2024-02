#include "canvas.h"
#include "static.h"

int main(int argc, char *argv[]) {
  Canvas canvas; // Create a default canvas
  Static *snow;  // pointer to a static snow drawable

  // Create a static snow drawable
  snow = new Static();

  // Add the snow to the canvas and render it.
  canvas.add(snow);
  canvas.render_loop();

  // Delete the snow drawable
  delete snow;

  return 0;
}
