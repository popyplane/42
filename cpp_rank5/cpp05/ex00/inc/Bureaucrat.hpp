#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

using	std::string;
using	std::cout;
using	std::endl;

class Bureaucrat {
	
	
	private :
		const string    _name;
		int             _grade;

	public :
		// canon
		Bureaucrat();
		Bureaucrat(const string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat  &operator=(const Bureaucrat &src);

		// getters
		const string    getName() const;
		int             getGrade() const;

		// grade management
		void			upGrade();
		void			downGrade();

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char	*what() const throw(); 
		};
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &src);

#endif