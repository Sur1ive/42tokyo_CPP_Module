#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed(const int num);
  Fixed(const float num);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

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
