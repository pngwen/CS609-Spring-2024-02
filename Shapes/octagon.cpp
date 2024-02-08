#include <cmath>
#include <iostream>
#include "octagon.h"

Octagon::Octagon(int x, int y, int sideLength) : _x(x), _y(y), _sideLength(sideLength) {}

Void Octagon::draw(Canvas* canvas) {
    for (int i = 0; i < 8; i++) {
        int x1 = _x + _sideLength * cos(2 * M_PI * i / 8);
        int y1 = _y + _sideLength * sin(2 * M_PI * i / 8);
        int x2 = _x + _sideLength * cos(2 * M_PI * (i + 1) / 8);
        int y2 = _y + _sideLength * sin(2 * M_PI * (i + 1) / 8);
        canvas->line(x1, y1, x2, y2);
    }
}

int main() {
    int x = 100;
    int y = 100;
    int sideLength = 50;

    Canvas canvas; // Assuming you have a Canvas class
    Octagon octagon(x, y, sideLength);
    octagon.draw(&canvas);

    return 0;
}
