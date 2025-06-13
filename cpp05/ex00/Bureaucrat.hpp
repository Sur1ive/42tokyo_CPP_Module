#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat {
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& other);

	void incrementGrade();
	void decrementGrade();

	std::string getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception {
	public:

	};

	class GradeTooLowException : public std::exception {
	public:

	};

private:
	std::string name_;
	int grade_;
};

#endif
