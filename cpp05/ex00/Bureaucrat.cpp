#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
	if (grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
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

std::string Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}
