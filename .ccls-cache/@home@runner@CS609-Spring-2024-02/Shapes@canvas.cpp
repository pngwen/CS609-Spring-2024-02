///////////////////////////////////////////////////////////////////////////
// File: canvas.cpp
// Purpose: Class implementation for a simple canvas that operates on drawables
// Author: Robert Lowe < rlowe@semo.edu >
///////////////////////////////////////////////////////////////////////////
#include "canvas.h"
#include "drawable.h"
#include <SDL.h>
#include <string>

// Constructor with width and height
Canvas::Canvas(const std::string &title, int width, int height) {
  // create the window
  _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, width, height,
                             SDL_WINDOW_RESIZABLE);

  // create the renderer
  _renderer = SDL_CreateRenderer(
      _window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!_renderer) {
    // Attempt to use software rendering if the accelerated renderer could not
    // be created
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_SOFTWARE);
  }
}

// Delegate Constructors
Canvas::Canvas(int width, int height)
    : Canvas("Drawing Canvas", width, height) {
  // this space left intentionally blank
  // constructor is delegated
}

Canvas::Canvas() : Canvas(640, 480) {
  // this space left intentionally blank
  // constructor is delegated
}

void Canvas::point(int x, int y) { SDL_RenderDrawPoint(_renderer, x, y); }

void Canvas::line(int x1, int y1, int x2, int y2) {
  SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void Canvas::color(int r, int g, int b) {
  SDL_SetRenderDrawColor(_renderer, r, g, b, 255);
}

void Canvas::render_loop() {
  SDL_Event event;

  // abort if we cannot render
  if (_renderer == nullptr) {
    return;
  }

  // main render loop
  bool done = false;
  while (!done) {
    // Brief delay
    SDL_Delay(33);

    // handle events
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = true;
      }
    }

    // clear the screen
    color(0, 0, 0);
    SDL_RenderClear(_renderer);

    // render all drawables (default color is white)
    color(255, 255, 255);
    for (auto itr = _drawables.begin(); itr != _drawables.end(); itr++) {
      (*itr)->draw(this);
    }

    // display the frame
    SDL_RenderPresent(_renderer);
  }

  // shut down SDL
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
  _window = nullptr;
  _renderer = nullptr;
}

int Canvas::width() {
  int w, h;

  SDL_GetWindowSize(_window, &w, &h);

  return w;
}

int Canvas::height() {
  int w, h;

  SDL_GetWindowSize(_window, &w, &h);

  return h;
}

void Canvas::add(Drawable *d) { _drawables.push_back(d); }

void Canvas::clear() { _drawables.clear(); }

std::vector<Drawable *>::const_iterator Canvas::begin() const {
  return _drawables.cbegin();
}

std::vector<Drawable *>::const_iterator Canvas::end() const {
  return _drawables.cend();
}