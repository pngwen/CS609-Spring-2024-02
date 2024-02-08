///////////////////////////////////////////////////////////////////////////
// File: rectangle.h
// Purpose: A drawable which draws a rectangle
// Author: [Hema Manikanta Reddy Karri, Sai Sravan Methuku, Vinay, Meghana Katne, Sravya Akavaram,Akhil Yalagandhula]
///////////////////////////////////////////////////////////////////////////
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "drawable.h"
#include "canvas.h"

class Rectangle : public Drawable {
public:
    Rectangle(int _x, int _y, int _w, int _h);

    void draw(Canvas* canvas) override;

private:
    int _x;
    int _y;
    int _w;
    int _h;
};

#endif // RECTANGLE_H
