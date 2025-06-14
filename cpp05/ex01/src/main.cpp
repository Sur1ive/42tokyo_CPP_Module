#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  Bureaucrat juniorBureaucrat("JuniorBureaucrat", 150);
  Form presidentialForm("PresidentialForm", 1, 1);
  Form commonForm("CommonForm", 150, 150);

  std::cout << "----------------Test 1------------------" << std::endl;
  try {
    std::cout << "Creating form with grade to sign 151 and grade to execute 1"
              << std::endl;
    Form form("TestForm", 151, 1);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------Test 2------------------" << std::endl;
  try {
    std::cout << "Creating form with grade to sign 0 and grade to execute 1"
              << std::endl;
    Form form("TestForm", 0, 1);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------Test 3------------------" << std::endl;
  try {
    std::cout << "Creating form with grade to sign 1 and grade to execute 151"
              << std::endl;
    Form form("TestForm", 1, 151);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------Test 4------------------" << std::endl;
  try {
    std::cout << "Creating form with grade to sign 1 and grade to execute 0"
              << std::endl;
    Form form("TestForm", 1, 0);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------Test 5------------------" << std::endl;
  try {
    std::cout << "Signing " << commonForm << " with " << juniorBureaucrat
              << std::endl;
    commonForm.signForm(juniorBureaucrat);
    std::cout << "Signing " << commonForm << " with " << juniorBureaucrat
              << std::endl;
    commonForm.signForm(juniorBureaucrat);

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------Test 6------------------" << std::endl;
  try {
    std::cout << "Signing " << presidentialForm << " with " << juniorBureaucrat
              << std::endl;
    presidentialForm.signForm(juniorBureaucrat);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
