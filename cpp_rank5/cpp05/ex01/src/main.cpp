#include "../inc/Bureaucrat.hpp"

int main()
{
	cout << "EX01" << endl << endl;
	cout << "First test" << endl << endl;	
	try 
	{
		Bureaucrat	rico("Rico", 150);
		Bureaucrat	louis("Louis", 1);
		Form		form001("Form001", 1, 1);
		
		cout << rico << louis << form001 << endl;
		rico.signForm(form001);
		louis.signForm(form001);
		louis.signForm(form001);
		cout << form001 << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	cout << endl << "Second test" << endl;
	try
	{
		Form	wrong01("Wrong01", 0, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Form	wrong10("Wrong10", 1, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Form	wrong91("Wrong91", 151, 100);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Form	wrong19("Wrong19", 100, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
}