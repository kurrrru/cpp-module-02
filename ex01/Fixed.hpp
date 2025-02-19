#pragma once
#include <iostream>

class Fixed {
 public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& rhs);

    explicit Fixed(const int value);
    explicit Fixed(const float value);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;

 private:
    int _value;
    static const int _fractionalBits = 8;
};

// なぜクラスの外で定義するのか？を解決する
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
