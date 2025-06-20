#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  void execute(const Bureaucrat &executor) const;

private:
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  std::string target_;
};

#endif
