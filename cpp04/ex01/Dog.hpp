#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog& other);
  virtual ~Dog();

  virtual void makeSound() const;

protected:
  Dog& operator=(const Dog& other);

private:
  Brain* brain_;
};

#endif
