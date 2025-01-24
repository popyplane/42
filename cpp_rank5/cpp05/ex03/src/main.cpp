#include "../inc/Bureaucrat.hpp"

int main()
{
    AForm *form = nullptr;
    try {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        Intern intern;

        // Shrubbery test, no changes here
        form = intern.makeForm("shrubbery creation", "Home");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;  // Delete after use

        // Robotomy test
        form = intern.makeForm("robotomy request", "Ricky");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;

        // Presidential test
        form = intern.makeForm("presidential pardon", "Ivan");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;

        // Invalid form test, where exception may occur
        form = intern.makeForm("Invalid", "Dummy");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form; // Delete even if exception occurs (inside catch)
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        if (form) delete form;  // Ensure deletion if form was created
    }
}
