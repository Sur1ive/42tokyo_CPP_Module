#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(), target_("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  checkExecuteAuthority(executor);
  std::cout << "Drilling noises nnnnnNNNNNNNNNNNNNNNNNNNNNN..." << std::endl;
  srand(time(NULL));
  if (rand() % 2)
    std::cout << target_ << " has been robotomized successfully" << std::endl;
  else
    std::cout << target_ << " robotomy failed" << std::endl;
}
