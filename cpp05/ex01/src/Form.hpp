#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
  Form(std::string name, int gradeToSign, int gradeToExecute);
  Form(const Form &other);
  ~Form();

  Form &operator=(const Form &other);

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
  std::string name_;
  bool isSigned_;
  int gradeToSign_;
  int gradeToExecute_;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
