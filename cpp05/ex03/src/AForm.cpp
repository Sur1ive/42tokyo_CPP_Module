#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name_("default"), isSigned_(false), gradeToSign_(150),
                gradeToExecute_(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false), gradeToSign_(gradeToSign),
      gradeToExecute_(gradeToExecute) {
  if (gradeToSign_ < 1 || gradeToExecute_ < 1)
    throw AForm::GradeTooHighException();
  if (gradeToSign_ > 150 || gradeToExecute_ > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name_(other.name_), isSigned_(other.isSigned_),
      gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
  isSigned_ = other.isSigned_;
  return *this;
}

std::string AForm::getName() const { return name_; }

bool AForm::getIsSigned() const { return isSigned_; }

int AForm::getGradeToSign() const { return gradeToSign_; }

int AForm::getGradeToExecute() const { return gradeToExecute_; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > gradeToSign_)
    throw AForm::GradeTooLowException();
  isSigned_ = true;
}

void AForm::checkExecuteAuthority(const Bureaucrat &executor) const {
  if (!getIsSigned())
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > gradeToExecute_)
    throw AForm::GradeTooLowException();
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Error: Form not signed";
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Error: Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Error: Grade too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
  os << obj.getName() << ", form grade to sign " << obj.getGradeToSign()
     << ", form grade to execute " << obj.getGradeToExecute()
     << ", form is signed " << obj.getIsSigned();
  return os;
}
