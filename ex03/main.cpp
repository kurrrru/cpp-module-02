#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
    std::cout << std::boolalpha;
    Point a, b, c, point;
    std::cout << "=== true cases ===" << std::endl;
    a = Point(Fixed(0), Fixed(0));
    b = Point(Fixed(0), Fixed(4));
    c = Point(Fixed(4), Fixed(0));
    point = Point(Fixed(1), Fixed(1));
    std::cout << bsp(a, b, c, point) << std::endl;

    a = Point(Fixed(0), Fixed(0));
    b = Point(Fixed(4), Fixed(0));
    c = Point(Fixed(0), Fixed(4));
    point = Point(Fixed(1), Fixed(1));
    std::cout << bsp(a, b, c, point) << std::endl;

    a = Point(Fixed(0), Fixed(0));
    b = Point(Fixed(2), Fixed(0));
    c = Point(Fixed(0), Fixed(3));
    point = Point(Fixed(0.98f), Fixed(1.52f));
    std::cout << bsp(a, b, c, point) << std::endl;

    std::cout << "=== false cases ===" << std::endl;
    a = Point(Fixed(0), Fixed(0));
    b = Point(Fixed(0), Fixed(4));
    c = Point(Fixed(4), Fixed(0));
    point = Point(Fixed(2), Fixed(2));
    std::cout << bsp(a, b, c, point) << std::endl;

    a = Point(Fixed(0), Fixed(0));
    b = Point(Fixed(0), Fixed(4));
    c = Point(Fixed(4), Fixed(0));
    point = Point(Fixed(-0.01f), Fixed(1));
    std::cout << bsp(a, b, c, point) << std::endl;

    a = Point(Fixed(0), Fixed(0));
    b = Point(Fixed(0), Fixed(4));
    c = Point(Fixed(4), Fixed(0));
    point = Point(Fixed(1), Fixed(-0.01f));
    std::cout << bsp(a, b, c, point) << std::endl;

    a = Point(Fixed(0), Fixed(0));
    b = Point(Fixed(0), Fixed(4));
    c = Point(Fixed(4), Fixed(0));
    point = Point(Fixed(3), Fixed(3));
    std::cout << bsp(a, b, c, point) << std::endl;

    std::cout << "=== degenerate cases ===" << std::endl;
    a = Point(Fixed(0), Fixed(0));
    b = Point(Fixed(0), Fixed(4));
    c = Point(Fixed(0), Fixed(2));
    point = Point(Fixed(0), Fixed(1));
    std::cout << bsp(a, b, c, point) << std::endl;

    a = Point(Fixed(1), Fixed(2));
    b = Point(Fixed(13), Fixed(38));
    c = Point(Fixed(-20), Fixed(-61));
    point = Point(Fixed(0), Fixed(-1));
    std::cout << bsp(a, b, c, point) << std::endl;

    a = Point(Fixed(3.8f), Fixed(3.8f));
    b = Point(Fixed(3.8f), Fixed(3.8f));
    c = Point(Fixed(3.8f), Fixed(3.8f));
    point = Point(Fixed(3.8f), Fixed(3.8f));
    std::cout << bsp(a, b, c, point) << std::endl;

    return 0;
}
