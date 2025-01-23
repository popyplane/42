#include "../inc/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return (*this);
}

void    ShrubberyCreationForm::performExec() const
{
    std::ofstream   outFile((this->_target + "_shrubbery").c_str());
    
outFile << "              v .   ._, |_  .," << endl
<< "           `-._\\/  .  \\ /    |/_" << endl
<< "               \\\\  _\\, y | \\//" << endl
<< "         _\\_.___\\\\, \\\\/ -.\\||" << endl
<< "           `7-,--.`._||  / / ," << endl
<< "           /'     `-. `./ / |/_.'" << endl
<< "                     |    |//" << endl
<< "                     |_    /" << endl
<< "                     |-   |" << endl
<< "                     |   =|" << endl
<< "                     |    |" << endl
<< "--------------------/ ,  . \\--------._" << endl
<< endl
<< endl
<< "       _-_" << endl
<< "    /~~   ~~\\" << endl
<< " /~~         ~~\\" << endl
<< "{               }" << endl
<< " \\  _-     -_  /" << endl
<< "   ~  \\\\ //  ~" << endl
<< "_- -   | | _- _" << endl
<< "  _ -  | |   -_" << endl
<< "      // \\\\" << endl
<< endl
<< endl
<< "            .        +          .      .          ." << endl
<< "     .            _        .                    ." << endl
<< "  ,              /;-._,-.____        ,-----.__" << endl
<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << endl
<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << endl
<< "                      ,    `./  \\:. `.   )==-'  ." << endl
<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << endl
<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << endl
<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << endl
<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << endl
<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << endl
<< "              \\:  `  X` _| _,\\/'   .-'"
<< ".               \":._:`\\____  /:'  /      .           ." << endl
<< "                    \\::.  :\\/:'  /              +" << endl
<< "   .                 `.:.  /:'  }      ." << endl
<< "           .           ):_(:;   \\           ." << endl
<< "                      /:. _/ ,  |"
<< "                   . (|::.     ,`                  ." << endl
<< "     .                |::.    {\\" << endl
<< "                      |::.\\  \\ `." << endl
<< "                      |:::(\\    |" << endl
<< "              O       |:::/{ }  |                  (o" << endl
<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << endl
<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << endl
<< "    ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << endl
<< endl;

}