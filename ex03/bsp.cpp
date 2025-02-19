#include "Fixed.hpp"
#include "Point.hpp"

Fixed signedArea(Point const a, Point const b, Point const c) {
    return (b.getX() - a.getX()) * (c.getY() - a.getY())
        - (c.getX() - a.getX()) * (b.getY() - a.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed abc = signedArea(a, b, c);
    Fixed abp = signedArea(a, b, point);
    Fixed bcp = signedArea(b, c, point);
    Fixed cap = signedArea(c, a, point);

    bool allPositive
        = abc > Fixed(0) && abp > Fixed(0) && bcp > Fixed(0) && cap > Fixed(0);
    bool allNegative
        = abc < Fixed(0) && abp < Fixed(0) && bcp < Fixed(0) && cap < Fixed(0);

    return allPositive || allNegative;
}
