#include "../inc/Bureaucrat.hpp"

int main()
{
	Bureaucrat  dumbBureaucrat("Dumb", 150);
	Bureaucrat  averageBureaucrat("Average", 70);
	Bureaucrat  aboveAverageBureaucrat("AboveAverage", 30);
	Bureaucrat  smartBureaucrat("Smart", 1);
	ShrubberyCreationForm	shrubbery("Home");
	RobotomyRequestForm  robotomy("Ricky");
	PresidentialPardonForm	presidential("Ivan");

	cout << "\n---------- EX02 Shrubbery Test ----------\n" << endl;
	dumbBureaucrat.signForm(shrubbery);
	dumbBureaucrat.executeForm(shrubbery);
	averageBureaucrat.signForm(shrubbery);
	averageBureaucrat.executeForm(shrubbery);
	aboveAverageBureaucrat.signForm(shrubbery);
	aboveAverageBureaucrat.executeForm(shrubbery);
	smartBureaucrat.signForm(shrubbery);
	smartBureaucrat.executeForm(shrubbery);

	cout << "\n---------- EX02 Robotomy Test ----------\n" << endl;
	srand(time(NULL));
	dumbBureaucrat.signForm(robotomy);
	dumbBureaucrat.executeForm(robotomy);
	averageBureaucrat.signForm(robotomy);
	averageBureaucrat.executeForm(robotomy);
	aboveAverageBureaucrat.signForm(robotomy);
	aboveAverageBureaucrat.executeForm(robotomy);
	smartBureaucrat.signForm(robotomy);
	smartBureaucrat.executeForm(robotomy);

	cout << "\n---------- EX02 Presidential Test ----------\n" << endl;
	dumbBureaucrat.signForm(presidential);
	dumbBureaucrat.executeForm(presidential);
	averageBureaucrat.signForm(presidential);
	averageBureaucrat.executeForm(presidential);
	aboveAverageBureaucrat.signForm(presidential);
	aboveAverageBureaucrat.executeForm(presidential);
	smartBureaucrat.signForm(presidential);
	smartBureaucrat.executeForm(presidential);
}