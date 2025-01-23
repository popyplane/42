#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

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
{
}

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
	if (_grade > 1)
		_grade--;
	else
		throw (GradeTooHighException());
}

void			Bureaucrat::downGrade()
{
	if (_grade < 149)
		_grade++;
	else
		throw (GradeTooLowException());
}

void			Bureaucrat::signForm(Form &f)
{
	if (f.isSigned())
		cout << this->_name << " couldn't sign " << f.getName() << " because  it's already signed !" << endl;
	else if (f.getSignGR() >= this->_grade)
	{
		cout << this->_name << " signed " << f.getName() << endl;
		f.beSigned(*this);
	}
	else
		cout << this->_name << " couldn't sign " << f.getName() << " because the grade required to sign it is higher than " << this->_name << "'s one." << endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << endl;
	return (out);
}


