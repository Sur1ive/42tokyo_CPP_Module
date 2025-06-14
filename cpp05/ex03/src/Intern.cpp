#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  const char *names[] = {"shrubbery creation", "robotomy request",
                         "presidential pardon"};
  AForm *forms[] = {new ShrubberyCreationForm(target),
                    new RobotomyRequestForm(target),
                    new PresidentialPardonForm(target)};

  for (int i = 0; i < 3; i++) {
    if (formName == names[i]) {
      return forms[i];
    }
  }
  throw std::invalid_argument("Invalid form name");
}
