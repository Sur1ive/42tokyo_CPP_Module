#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
  Bureaucrat juniorBureaucrat("JuniorBureaucrat", 150);
  Bureaucrat seniorBureaucrat("SeniorBureaucrat", 1);
  Intern intern;
  AForm *shrubberyForm = intern.makeForm("shrubbery creation", "Test");
  AForm *robotomyForm = intern.makeForm("robotomy request", "Test");
  AForm *presidentialForm = intern.makeForm("presidential pardon", "Test");

  std::cout << "----------------Test 1------------------" << std::endl;
  juniorBureaucrat.executeForm(*shrubberyForm);

  std::cout << "----------------Test 2------------------" << std::endl;
  seniorBureaucrat.executeForm(*shrubberyForm);

  std::cout << "----------------Test 3------------------" << std::endl;
  juniorBureaucrat.signForm(*shrubberyForm);

  std::cout << "----------------Test 4------------------" << std::endl;
  seniorBureaucrat.signForm(*shrubberyForm);
  seniorBureaucrat.signForm(*robotomyForm);
  seniorBureaucrat.signForm(*presidentialForm);

  std::cout << "----------------Test 5------------------" << std::endl;
  juniorBureaucrat.executeForm(*shrubberyForm);
  juniorBureaucrat.executeForm(*robotomyForm);
  juniorBureaucrat.executeForm(*presidentialForm);

  std::cout << "----------------Test 6------------------" << std::endl;
  seniorBureaucrat.executeForm(*shrubberyForm);

  std::cout << "----------------Test 7------------------" << std::endl;
  seniorBureaucrat.executeForm(*robotomyForm);

  std::cout << "----------------Test 8------------------" << std::endl;
  seniorBureaucrat.executeForm(*presidentialForm);

  std::cout << "----------------Test 9------------------" << std::endl;
  try {
    AForm *noexistForm = intern.makeForm("noexist", "Test");
    std::cout << noexistForm << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  delete shrubberyForm;
  delete robotomyForm;
  delete presidentialForm;
  return 0;
}
