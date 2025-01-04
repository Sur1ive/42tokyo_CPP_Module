#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
  Animal** animals = new Animal*[10];

  std::cout << "---------------test1: create---------------- " << std::endl;

  for (int i = 0; i < 5; ++i) {
    animals[i] = new Cat();
  }
  for (int i = 5; i < 10; ++i) {
    animals[i] = new Dog();
  }

  for (int i = 0; i < 10; ++i) {
    animals[i]->makeSound();
  }

  std::cout << "---------------test2: deep copy---------------- " << std::endl;

  Cat cat = *(Cat *)animals[0];

  std::cout << "---------------test3: delete---------------- " << std::endl;

  for (int i = 0; i < 10; ++i) {
      delete animals[i];
  }
  delete[] animals;

  std::cout << "---------------test2: deep copy---------------- " << std::endl;

  cat.makeSound();

  std::cout << "---------------test4: new animal---------------- " << std::endl;

  // Animal animal = Animal(); // can't do this because Animal is an abstract class

  return 0;
}
