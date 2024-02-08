

//{Vivekananda reddy Tippireddy, Bhargava Sita Rami Reddy Vippala, Rakesh Reddy Puligari, Eswar Chandu Vunnam, Tarun Singh Kshatriya}
#ifndef OCTAGON_H
#define OCTAGON_H

#include "iostream""
#include "cmath"

Void Draw

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

