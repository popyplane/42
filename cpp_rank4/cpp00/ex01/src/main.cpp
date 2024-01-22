#include "../inc/phoneBook.hpp"

int	main()
{
	PhoneBook	myAwesomePhoneBook;
	std::string	input;

	std::cout << BLUE << "Welcome to your awesome phonebook !" << ENDCOLOR << std::endl << std::endl;

	while (42)
	{
		std::cout << std::endl;
		std::cout << BLUE << "Enter Command [ADD] [SEARCH] [EXIT]: " << ENDCOLOR;

		std::getline(std::cin, input);
		std::cout << std::endl;

		if (std::cin.eof())
			break;

		if (input.compare("ADD") == 0)
		{
			myAwesomePhoneBook.add();
		}
		else if (input.compare("SEARCH") == 0)
		{
			myAwesomePhoneBook.search();
		}
		else if (input.compare("EXIT") == 0)
		{
			std::cout << BLUE << "CIAOOOO ;)" << ENDCOLOR << std::endl;
			break;
		}
		else
		{
			std::cout << RED << "Input \"" << input << "\" is invalid" << ENDCOLOR << std::endl;
		}
	}
	return (0);
}