#include "../inc/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	bureaucrat("Bureaucrat", 1);
		Intern 		intern;
		AForm		*form;
	
		try
		{
			std::cout << "\n---------- EX03 Shrubbery Test ----------\n" << std::endl;	
			form = intern.makeForm("shrubbery creation", "Home");
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
		catch (const std::exception &e)
		{
			delete form;
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "\n---------- EX03 Robotomy Test ----------\n" << std::endl;
			form = intern.makeForm("robotomy request", "Ricky");
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
		catch (const std::exception &e)
		{
			delete form;
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::cout << "\n---------- EX03 Presidential Test ----------\n" << std::endl;
			form = intern.makeForm("presidential pardon", "Ivan");
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
		catch (const std::exception &e)
		{
			delete form;
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "\n---------- EX03 Invalid Test ----------\n" << std::endl;
			form = intern.makeForm("Invalid", "Dummy");
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
		catch (const std::exception &e)
		{
			delete form;
			std::cout << e.what() << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Unhandled exception: " << e.what() << std::endl;
	}
	return (0);
}