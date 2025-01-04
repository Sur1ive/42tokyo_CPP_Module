#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat& other);
  ~WrongCat();

protected:
  WrongCat& operator=(const WrongCat& other);
};

#endif
