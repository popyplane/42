#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(const string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat		&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return (*this);
	_grade = src.getGrade();
	return (*this);
}

const string	Bureaucrat::getName() const
{
	return (_name);
}

int				Bureaucrat::getGrade() const
{
	return (_grade);
}

void			Bureaucrat::upGrade()
{
	try
	{
		if (_grade < 2)
			throw (GradeTooHighException());
		_grade++;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
}

void			Bureaucrat::downGrade()
{
	try
	{
		if (_grade > 149)
			throw (GradeTooLowException());
		_grade++;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
}

void			Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		cout << this->_name << " signed " << f.getName() << endl;
	}
	catch (std::exception &e)
	{
		cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << endl;
	}
}

void		Bureaucrat::executeForm(AForm &f)
{
	try
	{
		cout << this->_name << " tries to execute " << f.getName() << endl;
		f.execute(*this);
	}
	catch (std::exception &e)
	{
		cout << this->_name << " couldn't execute " << f.getName() << " because " << e.what() << endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("(Bureaucrat) GradeTooHighException");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("(Bureaucrat) GradeTooLowException");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << endl;
	return (out);
}


