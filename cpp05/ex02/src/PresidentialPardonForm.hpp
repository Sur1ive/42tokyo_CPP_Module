#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();

  void execute(const Bureaucrat &executor) const;

private:
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  std::string target_;
};

#endif
