#ifndef FIXED_HPP
# define FIXWD_HPP

class Fixed {
public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int value_;
  static const int numberOfFractionalBits = 8;
};

#endif