#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed(const int num);
  Fixed(const float num);
  ~Fixed();

  Fixed& operator=(const Fixed& other);
  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;
  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;
  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  static Fixed& max(Fixed& f1, Fixed& f2);
  static const Fixed& max(const Fixed &f1, const Fixed &f2);
  static Fixed& min(Fixed& f1, Fixed& f2);
  static const Fixed& min(const Fixed &f1, const Fixed &f2);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int value_;
  static const int numberOfFractionalBits_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
