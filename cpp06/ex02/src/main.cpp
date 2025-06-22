#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void) {
  srand(time(NULL));
  int random = rand() % 3;
  if (random == 0) {
    std::cout << "generated A" << std::endl;
    return new A();
  } else if (random == 1) {
    std::cout << "generated B" << std::endl;
    return new B();
  } else {
    std::cout << "generated C" << std::endl;
    return new C();
  }
}

void identify(Base* p){
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  }
}

void identify(Base& p){
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  } catch (std::exception& e) {}
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
  } catch (std::exception& e) {}
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
  } catch (std::exception& e) {}
}

int main() {
  Base *base = generate();
  identify(*base);
  identify(base);
  delete base;
}
