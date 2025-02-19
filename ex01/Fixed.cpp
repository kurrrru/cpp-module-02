#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &other)
        setRawBits(other.getRawBits());
    return *this;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    setRawBits(value << this->_fractionalBits);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    setRawBits(static_cast<int>(value * (1 << this->_fractionalBits) + 0.5));
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

int Fixed::toInt(void) const {
    return getRawBits() >> this->_fractionalBits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(getRawBits()) / (1 << this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
