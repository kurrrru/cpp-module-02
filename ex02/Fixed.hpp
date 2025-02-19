#pragma once
#include <iostream>

class Fixed {
 public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    explicit Fixed(const int value);
    explicit Fixed(const float value);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;

    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    const Fixed operator+(const Fixed& rhs) const;
    const Fixed operator-(const Fixed& rhs) const;
    const Fixed operator*(const Fixed& rhs) const;
    const Fixed operator/(const Fixed& rhs) const;

    Fixed& operator++();
    const Fixed operator++(int);
    Fixed& operator--();
    const Fixed operator--(int);

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

 private:
    int _value;
    static const int _fractionalBits = 8;
};

// なぜクラスの外で定義するのか？を解決する
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
