#ifndef OCTAGON_H
#define OCTAGON_H

#include "drawable.h"
#include "canvas.h"

class Octagon : public Drawable {
public:
    Octagon(int _x, int _y, int _sideLength);

    void draw(Canvas* canvas) override;

private:
    int _x;
    int _y;
    int _sideLength;
};

#endif

