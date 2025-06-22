#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string target) {
  const char *names[] = {"shrubbery creation", "robotomy request",
                         "presidential pardon"};
  AForm *forms[] = {new ShrubberyCreationForm(target),
                    new RobotomyRequestForm(target),
                    new PresidentialPardonForm(target)};

  int form_i = -1;
  for (int i = 0; i < 3; i++) {
    if (formName == names[i]) {
      form_i = i;
      continue;
    }
    delete forms[i];
  }
  if (form_i != -1)
    return forms[form_i];
  throw std::invalid_argument("Invalid form name");
}
