#pragma once

class Fixed {
 public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

 private:
    int _value;
    static const int _fractionalBits = 8;
};
