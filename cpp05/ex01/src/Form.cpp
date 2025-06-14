#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false), gradeToSign_(gradeToSign),
      gradeToExecute_(gradeToExecute) {
  if (gradeToSign_ < 1 || gradeToExecute_ < 1)
    throw Form::GradeTooHighException();
  if (gradeToSign_ > 150 || gradeToExecute_ > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : name_(other.name_), isSigned_(other.isSigned_),
      gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {
}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
  name_ = other.name_;
  gradeToSign_ = other.gradeToSign_;
  gradeToExecute_ = other.gradeToExecute_;
  isSigned_ = other.isSigned_;
  return *this;
}

std::string Form::getName() const { return name_; }

bool Form::getIsSigned() const { return isSigned_; }

int Form::getGradeToSign() const { return gradeToSign_; }

int Form::getGradeToExecute() const { return gradeToExecute_; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > gradeToSign_)
    throw Form::GradeTooLowException();
  isSigned_ = true;
}

void Form::signForm(const Bureaucrat &bureaucrat) {
  if (isSigned_) {
    std::cout << bureaucrat.getName() << " couldn't sign " << name_
              << " because it is already signed" << std::endl;
    return;
  }

  try {
    beSigned(bureaucrat);
    std::cout << bureaucrat.getName() << " signed " << name_ << std::endl;
  } catch (std::exception &e) {
    std::cout << bureaucrat.getName() << " couldn't sign " << name_
              << " because " << e.what() << std::endl;
  }
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Error: Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Error: Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &obj) {
  os << obj.getName() << ", form grade to sign " << obj.getGradeToSign()
     << ", form grade to execute " << obj.getGradeToExecute()
     << ", form is signed " << obj.getIsSigned();
  return os;
}
