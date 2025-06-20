#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
  Form();
  Form(std::string name, int gradeToSign, int gradeToExecute);
  Form(const Form &other);
  ~Form();

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  Form &operator=(const Form &other);

  const std::string name_;
  bool isSigned_;
  const int gradeToSign_;
  const int gradeToExecute_;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
