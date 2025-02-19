#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
    // std::cout << "Copy constructor called" << std::endl;
    setRawBits(src.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    // std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
        setRawBits(rhs.getRawBits());
    return *this;
}

Fixed::Fixed(const int value) {
    // std::cout << "Int constructor called" << std::endl;
    setRawBits(value << this->_fractionalBits);
}

Fixed::Fixed(const float value) {
    // std::cout << "Float constructor called" << std::endl;
    setRawBits(static_cast<int>(value * (1 << this->_fractionalBits) + 0.5));
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

int Fixed::toInt(void) const {
    return getRawBits() >> this->_fractionalBits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(getRawBits()) / (1 << this->_fractionalBits);
}

bool Fixed::operator>(const Fixed& rhs) const {
    return getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const {
    return getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const {
    return getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return getRawBits() != rhs.getRawBits();
}

const Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(getRawBits() + rhs.getRawBits());
    return result;
}

const Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(getRawBits() - rhs.getRawBits());
    return result;
}

// complicated to handle overflow without using long
const Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits((static_cast<long>(getRawBits()) * rhs.getRawBits())
        >> this->_fractionalBits);
    return result;
}

const Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits((static_cast<long>(getRawBits())
        << this->_fractionalBits) / rhs.getRawBits());
    return result;
}

Fixed& Fixed::operator++() {
    setRawBits(getRawBits() + 1);
    return *this;
}

const Fixed Fixed::operator++(int) {
    Fixed ret(*this);
    operator++();
    return ret;
}

Fixed& Fixed::operator--() {
    setRawBits(getRawBits() - 1);
    return *this;
}

const Fixed Fixed::operator--(int) {
    Fixed ret(*this);
    operator--();
    return ret;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
