#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"

# define FORM_NB 3

class Intern
{
	public :
		// canon
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern	&operator=(const Intern &src);

		// member functions
		AForm	*makeForm(string formName, string target);

		// excpetion classes
		class InvalidFormNameException {
			public :
				virtual const char *what() const throw();
		};
};

#endif