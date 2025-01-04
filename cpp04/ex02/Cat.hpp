#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat& other);
  virtual ~Cat();

  virtual void makeSound() const;

protected:
  Cat& operator=(const Cat& other);

private:
  Brain* brain_;
};

#endif
