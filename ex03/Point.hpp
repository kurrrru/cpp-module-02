#pragma once

#include "Fixed.hpp"

class Point {
 public:
    Point();
    Point(const Point& other);
    Point(const Fixed x, const Fixed y);
    Point& operator=(const Point& rhs);
    ~Point();

    Fixed getX(void) const;
    Fixed getY(void) const;

 private:
    Fixed _x;
    Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
