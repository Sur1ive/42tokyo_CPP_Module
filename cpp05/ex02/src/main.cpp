#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat juniorBureaucrat("JuniorBureaucrat", 150);
  Bureaucrat seniorBureaucrat("SeniorBureaucrat", 1);
  ShrubberyCreationForm shrubberyForm("Test");
  RobotomyRequestForm robotomyForm("Test");
  PresidentialPardonForm presidentialForm("Test");

  std::cout << "----------------Test 1------------------" << std::endl;
  juniorBureaucrat.executeForm(shrubberyForm);

  std::cout << "----------------Test 2------------------" << std::endl;
  seniorBureaucrat.executeForm(shrubberyForm);

  std::cout << "----------------Test 3------------------" << std::endl;
  juniorBureaucrat.signForm(shrubberyForm);

  std::cout << "----------------Test 4------------------" << std::endl;
  seniorBureaucrat.signForm(shrubberyForm);
  seniorBureaucrat.signForm(robotomyForm);
  seniorBureaucrat.signForm(presidentialForm);

  std::cout << "----------------Test 5------------------" << std::endl;
  juniorBureaucrat.executeForm(shrubberyForm);
  juniorBureaucrat.executeForm(robotomyForm);
  juniorBureaucrat.executeForm(presidentialForm);

  std::cout << "----------------Test 6------------------" << std::endl;
  seniorBureaucrat.executeForm(shrubberyForm);

  std::cout << "----------------Test 7------------------" << std::endl;
  seniorBureaucrat.executeForm(robotomyForm);

  std::cout << "----------------Test 8------------------" << std::endl;
  seniorBureaucrat.executeForm(presidentialForm);

  return 0;
}
