#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "../inc/Bureaucrat.hpp"

class   PresidentialPardonForm : public AForm
{
    private :
        string    _target;
    
    public :
        // canon
        PresidentialPardonForm();
        PresidentialPardonForm(string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm  &operator=(const PresidentialPardonForm &src);

        // member function
        void    performExec() const;
};

#endif