#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name_(name), grade_(grade) {
  if (grade_ < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade_ > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  name_ = other.name_;
  grade_ = other.grade_;
  return *this;
}

void Bureaucrat::incrementGrade() {
  if (grade_ <= 1)
    throw Bureaucrat::GradeTooHighException();
  grade_--;
}

void Bureaucrat::decrementGrade() {
  if (grade_ >= 150)
    throw Bureaucrat::GradeTooLowException();
  grade_++;
}

void Bureaucrat::signForm(Form &form) const {
  if (form.getIsSigned()) {
    std::cout << getName() << " couldn't sign " << form.getName()
              << " because it is already signed" << std::endl;
    return;
  }

  try {
    form.beSigned(*this);
    std::cout << getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << getName() << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

std::string Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
  return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Error: Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Error: Grade too low";
}
