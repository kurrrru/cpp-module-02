#pragma once

class Fixed {
 public:
    Fixed();
	~Fixed();
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

 private:
	int _value;
	static const int _fractionalBits = 8;
};
