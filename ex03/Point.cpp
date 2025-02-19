#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {
}

Point::~Point() {
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        _x = other.getX();
        _y = other.getY();
    }
    return *this;
}

Fixed Point::getX(void) const {
    return _x;
}

Fixed Point::getY(void) const {
    return _y;
}
