#include<iostream>
#include"rectangle.h"
#include"canvas.h"
#include "drawable.h"
#include "canvas.h"


Rectangle::Rectangle(int _x, int _y, int _w, int _h) : _x(_x), _y(_y), _w(_w), _h(_h) {}

void Rectangle::draw(Canvas* canvas) {
    // Compute the other extremes
    int rx = _x + _w;
    int ly = _y + _h;

    // Draw the shape
    canvas->line(_x, _y, rx, _y); // Top linch
    canvas->line(_x,ly,rx,ly);
    canvas->line(_x,_y,_x,ly);
    canvas->line(rx, _y, rx, ly); 
}
