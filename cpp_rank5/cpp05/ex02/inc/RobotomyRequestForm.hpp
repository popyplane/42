#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "../inc/Bureaucrat.hpp"

class   RobotomyRequestForm : public AForm
{
    private :
        string    _target;
    
    public :
        // canon
        RobotomyRequestForm();
        RobotomyRequestForm(string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        RobotomyRequestForm  &operator=(const RobotomyRequestForm &src);

        // member function
        void    performExec() const;
};

#endif