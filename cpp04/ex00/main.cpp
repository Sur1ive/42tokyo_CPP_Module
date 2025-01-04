#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  std::cout << "---------------test1: right sound---------------- " << std::endl;

  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  std::cout << "---------------test2: wrong sound---------------- " << std::endl;

  const WrongAnimal* meta1 = new WrongAnimal();
  const WrongAnimal* i1 = new WrongCat();

  std::cout << i1->getType() << " " << std::endl;
  i1->makeSound(); //will output the wrong animal sound!
  meta1->makeSound();

  delete meta1;
  delete i1;

  return 0;
}
