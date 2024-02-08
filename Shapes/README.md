# Canvas Class

## Overview

`Canvas` is a class for creating a simple graphical canvas that renders instances of `Drawable`.

## Constructors

### `Canvas(const std::string& title, int width, int height)`
Creates a canvas with a specified title, width, and height.

### `Canvas(int width, int height)`
Creates a canvas with a default title ("Drawing Canvas") and specified dimensions.

### `Canvas()`
Creates a canvas with default title and dimensions (640x480).

## Methods

### `void point(int x, int y)`
Draws a point at the given coordinates.

### `void line(int x1, int y1, int x2, int y2)`
Draws a line between two given points.

### `void color(int r, int g, int b)`
Sets the drawing color.

### `void render_loop()`
Begins the render loop.

### `int width()`
Returns the canvas width.

### `int height()`
Returns the canvas height.

### `void add(Drawable* d)`
Adds a `Drawable` object to the canvas.

### `void clear()`
Clears all `Drawable` objects from the canvas.

### `std::vector<Drawable*>::const_iterator begin() const`
Returns a const iterator to the beginning of the canvas's drawables.

### `std::vector<Drawable*>::const_iterator end() const`
Returns a const iterator to the end of the canvas's drawables.

---

# Drawable Interface

## Overview

`Drawable` is an abstract interface that specifies a draw method for drawable objects within a `Canvas`.

## Methods

### `void draw(Canvas *canvas) = 0`
Pure virtual function to draw the object on the canvas. Must be implemented in derived classes.

## Example Implementation

```cpp
class Circle : public Drawable {
public:
  void draw(Canvas *canvas) override {
    // Implementation to draw a circle on the given canvas
  }
};
```

A program which uses this object would have the following basic steps:
1. Create a Canvas object.
2. Create instances of all your drawable objects.
3. Add your Drawable objects to the Canvas instance.
4. Enter the render loop.

For example, consider the following code snippet:
```cpp
Canvas canvas;
Drawable *circle;

//create the drawable objects
circle = new Circle();

//add the drawable objects to the canvas
canvas.add(circle);

//display the drawing
canvas.render_loop();
```

Animations are also possible as the render loop redraws each of its object at 
a target frame rate of approximately 30 frames per second. (See the files 
`static.cpp`, and `static_test.cpp` for more information.)