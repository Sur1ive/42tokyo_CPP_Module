#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog& other);
  virtual ~Dog();

  virtual void makeSound() const;

protected:
  Dog& operator=(const Dog& other);
};

#endif
