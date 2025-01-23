#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm  &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this == &src)
    {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return (*this);
}

void    RobotomyRequestForm::performExec() const
{
    cout << "*** Drilling noises ***" << endl;
    if (rand() % 2 == 0)
        cout << this->_target << " has been robotomised !" << endl;
    else
        cout << this->_target << "'s robotomy failed !" << endl;
}