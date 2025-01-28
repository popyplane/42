#include "../inc/Bureaucrat.hpp"

int main() {
	try {
		Intern intern;
		Bureaucrat bureaucrat("Bureaucrat", 1);

		std::cout << "---------- EX03 Shrubbery Test ----------" << std::endl;
		AForm *shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
		bureaucrat.signForm(*shrubberyForm);
		bureaucrat.executeForm(*shrubberyForm);
		delete shrubberyForm;

		std::cout << "---------- EX03 Robotomy Test ----------" << std::endl;
		AForm *robotomyForm = intern.makeForm("robotomy request", "Ricky");
		bureaucrat.signForm(*robotomyForm);
		bureaucrat.executeForm(*robotomyForm);
		delete robotomyForm;

		std::cout << "---------- EX03 Presidential Test ----------" << std::endl;
		AForm *pardonForm = intern.makeForm("presidential pardon", "Ivan");
		bureaucrat.signForm(*pardonForm);
		bureaucrat.executeForm(*pardonForm);
		delete pardonForm;

		std::cout << "---------- EX03 Invalid Test ----------" << std::endl;
		AForm *invalidForm = intern.makeForm("invalid form name", "dummy");
		delete invalidForm;

	}
	catch (const Intern::InvalidFormNameException &e)
	{
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	}

	return 0;
}

