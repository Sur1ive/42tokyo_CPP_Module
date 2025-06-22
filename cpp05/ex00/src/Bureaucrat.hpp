#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();

  void incrementGrade();
  void decrementGrade();

  std::string getName() const;
  int getGrade() const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  Bureaucrat &operator=(const Bureaucrat &other);
  const std::string name_;
  int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
