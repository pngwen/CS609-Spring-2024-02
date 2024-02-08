#include "drawable.h"
#include "canvas.h"
#include "triangle.h"
#include "cmath"

Triangle::Triangle(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) {
    this->_x1 = _x1;
    this->_y1 = _y1;
    this->_x2 = _x2;
    this->_y2 = _y2;
    this->_x3 = _x3;
    this->_y3 = _y3;
}

void Triangle::draw(Canvas* canvas) {
    // Triangle drawing logic using Bresenham's line algorithm
    drawLine(canvas, _x1, _y1, _x2, _y2);
    drawLine(canvas, _x2, _y2, _x3, _y3);
    drawLine(canvas, _x3, _y3, _x1, _y1);
}

void Triangle::drawLine(Canvas* canvas, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        canvas->point(x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}