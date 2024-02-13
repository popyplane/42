#include "../inc/Harl.hpp"

// PRIVATE ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void	Harl::debug()
{
	cout
		<< "[ DEBUG ]" << endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << endl;
}

void	Harl::info()
{
	cout
		<< "[ INFO ]" << endl
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << endl;
}

void	Harl::warning()
{
	cout
		<< "[ WARNING ]" << endl
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << endl;
}

void	Harl::error()
{
	cout
		<< "[ ERROR ]" << endl
		<< "This is unacceptable ! I want to speak to the manager now." << endl;
}

// PUBLIC /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void	Harl::complain( string level )
{
	void		(Harl::*tabfct[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string		tablvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		//cout << level << " " << i << endl;
		if (!level.compare(tablvl[i]))
		{
			(this->*tabfct[i])();
			return;
		}
	}
	cout 
		<< "[ " << level << " ]" << endl
		<< "This level of complaint doesn't exist." << endl;
}

Harl::Harl()
{
	cout << "Harl has been created" << endl;
}

Harl::~Harl()
{
	cout << "Harl has been destroyed" << endl;
}
