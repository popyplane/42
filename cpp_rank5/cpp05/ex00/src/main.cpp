#include "../inc/Bureaucrat.hpp"

int main()
{
	cout << "EX00" << endl << endl;
	cout << "First test" << endl;	
	try 
	{
		Bureaucrat	rico("Rico", 150);
		rico.downGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr <<
			e.what()
			<< endl;
	}
	try 
	{
		Bureaucrat	piper("Piper", 10);
		for(int i = 0; i < 10; i++)
		{
			piper.upGrade();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr <<
			e.what()
			<< endl;
	}
	cout << endl << "Second test" << endl;
	try
	{
		Bureaucrat	amber("Amber", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr <<
			e.what()
			<< endl;
	}
	try
	{
		Bureaucrat	edgar("Edgar", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr <<
			e.what()
			<< endl;
	}

	cout << "Last test" << endl << endl;
	Bureaucrat	noname;
	cout <<	noname << endl;
}