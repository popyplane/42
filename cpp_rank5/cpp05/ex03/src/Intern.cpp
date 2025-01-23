#include "../inc/Bureaucrat.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern::~Intern()
{}

Intern  &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm   *Intern::makeForm(string formName, string target)
{
	const string    availableName[FORM_NB] = {"shrubbery creation",
												"presidential pardon",
												"robotomy request"};
	AForm           *availableForm[FORM_NB] = {new ShrubberyCreationForm(target),
												new PresidentialPardonForm(target),
												new RobotomyRequestForm(target)};
	AForm           *selectedForm = nullptr;

	for (int i = 0; i < FORM_NB; i++)
	{
		if (formName == availableName[i])
		{
			cout << "Intern creates " << formName << " form." << endl;
			selectedForm = availableForm[i];
		}
		else
			delete (availableForm[i]);
	}
	if (selectedForm == nullptr)
		throw (InvalidFormNameException());
	return (selectedForm);
}

const char  *Intern::InvalidFormNameException::what() const throw()
{
	return ("(Intern) InvalidFormNameException was called");
}