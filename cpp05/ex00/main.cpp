#include "Bureaucrat.hpp"

int main() {
	std::cout << "----------------Test 1------------------" << std::endl;
	try {
		std::cout << "Creating bureaucrat with grade 151" << std::endl;
		Bureaucrat bureaucrat("test", 151);
		std::cout << bureaucrat << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------Test 2------------------" << std::endl;
	try {
		std::cout << "Creating bureaucrat with grade 0" << std::endl;
		Bureaucrat bureaucrat("test", 0);
		std::cout << bureaucrat << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------Test 3------------------" << std::endl;
	try {
		std::cout << "Creating bureaucrat with grade 1" << std::endl;
		Bureaucrat bureaucrat("test", 1);
		std::cout << bureaucrat << std::endl;
		std::cout << "Incrementing grade" << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------Test 4------------------" << std::endl;
	try {
		std::cout << "Creating bureaucrat with grade 150" << std::endl;
		Bureaucrat bureaucrat("test", 150);
		std::cout << bureaucrat << std::endl;
		std::cout << "Decrementing grade" << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------Test 5------------------" << std::endl;
	try {
		std::cout << "Creating bureaucrat with grade 150" << std::endl;
		Bureaucrat bureaucrat("test", 150);
		std::cout << bureaucrat << std::endl;
		std::cout << "Incrementing grade" << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << "Decrementing grade" << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
