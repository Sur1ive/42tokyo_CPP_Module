#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &executor) const;

private:
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  std::string target_;
};

#endif
