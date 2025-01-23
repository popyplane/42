#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "../inc/Bureaucrat.hpp"
# include <fstream>

class   ShrubberyCreationForm : public AForm 
{
    private :
        string    _target;
    
    public :
        // canon
        ShrubberyCreationForm();
        ShrubberyCreationForm(string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm  &operator=(const ShrubberyCreationForm &src);

        // member function
        void    performExec() const;
};

#endif