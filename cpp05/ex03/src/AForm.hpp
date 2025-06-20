#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(std::string name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &other);
  virtual ~AForm();

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(const Bureaucrat &executor) const = 0;
  void checkExecuteAuthority(const Bureaucrat &executor) const;

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  AForm &operator=(const AForm &other);

  const std::string name_;
  bool isSigned_;
  const int gradeToSign_;
  const int gradeToExecute_;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
