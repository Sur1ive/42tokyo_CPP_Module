#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& other);
  virtual ~WrongAnimal();
  WrongAnimal& operator=(const WrongAnimal& other);

  virtual void makeSound() const;
  std::string getType() const;

protected:
  std::string type_;
};

#endif
