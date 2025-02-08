#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const Point& src) : _x(src.getX()), _y(src.getY()) {
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {
}

Point::~Point() {
}

Point& Point::operator=(const Point& rhs) {
	if (this != &rhs) {
		_x = rhs.getX();
		_y = rhs.getY();
	}
	return *this;
}

Fixed Point::getX(void) const {
	return _x;
}

Fixed Point::getY(void) const {
	return _y;
}
