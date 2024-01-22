#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "phoneBook.hpp"

// CLASS CONTACT //////////////////////////////////////////

class Contact
{
	private:

		std::string		_firstName;
		std::string 	_lastName;
		std::string 	_nickname;
		std::string 	_darkestSecret;
		std::string		_phoneNumber;

		bool			_setFirstName();
		bool			_setLastName();
		bool			_setNickname();
		bool			_setDarkestSecret();
		bool			_setPhoneNumber();

		std::string		_getTrimString(std::string str) const;


	public:

		Contact();
		~Contact();

		bool		setContact();
		void		displayShortContact(int idx) const;
		void		displayContact() const;

		std::string	getFirstName() const;
		std::string	getlastName() const;
		std::string	getNickname() const;
};

// CONTACT PRIVATE MEMBERS ////////////////////////////////

bool	Contact::_setFirstName()
{
	std::string	buffer;

	std::cout << GREEN << "First Name: " << ENDCOLOR;
	std::getline(std::cin, buffer);
	std::cout << std::endl;
	this->_firstName = buffer;
	return (true);
}

bool	Contact::_setLastName()
{
	std::string	buffer;

	std::cout << GREEN << "Last Name: " << ENDCOLOR;
	std::getline(std::cin, buffer);
	std::cout << std::endl;
	this->_lastName = buffer;
	return (true);
}

bool	Contact::_setNickname()
{
	std::string	buffer;

	std::cout << GREEN << "Nickname: " << ENDCOLOR;
	std::getline(std::cin, buffer);
	std::cout << std::endl;
	this->_nickname = buffer;	
	return (true);
}

bool	Contact::_setDarkestSecret()
{
	std::string	buffer;

	std::cout << GREEN << "Darkest Secret: " << ENDCOLOR;
	std::getline(std::cin, buffer);
	std::cout << std::endl;
	this->_darkestSecret = buffer;
	return (true);
}

bool	Contact::_setPhoneNumber()
{
	std::string	buffer;

	std::cout << GREEN << "Phone Number: " << ENDCOLOR;
	std::getline(std::cin, buffer);
	std::cout << std::endl;
	this->_phoneNumber = buffer;
	return (true);
}

std::string		Contact::_getTrimString(std::string str) const
{
	if (str.length() < 11)
		str.resize(10, ' ');
	else
	{
		str.resize(9);
		str.push_back('.');
	}
	return (str);
}

// CONTACT PUBLIC MEMBERS /////////////////////////////////

void		Contact::displayShortContact(int idx) const
{
	std::string	trimFirstName = _getTrimString(getFirstName());
	std::string trimLastName = _getTrimString(getlastName());
	std::string	trimNickame = _getTrimString(getNickname());

	std::cout << YELLOW << idx + 1 << "         ";
	std::cout << "|" << trimFirstName;
	std::cout << "|" << trimLastName;
	std::cout << "|" << trimNickame;
	std::cout << "|" << ENDCOLOR << std::endl;
	std::setw(10);
}

bool	Contact::setContact(void)
{
	if (this->_setFirstName()
		&& this->_setLastName()
		&& this->_setNickname()
		&& this->_setDarkestSecret()
		&& this->_setPhoneNumber())
		return (true);
	return (false);
}

void	Contact::displayContact() const
{
	std::cout << BLUE << "First Name : " << ENDCOLOR << YELLOW << this->_firstName << ENDCOLOR << std::endl;
	std::cout << BLUE << "Last Name : " << ENDCOLOR << YELLOW << this->_lastName << ENDCOLOR << std::endl;
	std::cout << BLUE << "Nickname : " << ENDCOLOR << YELLOW << this->_nickname << ENDCOLOR << std::endl;
	std::cout << BLUE << "Darkest Secret : " << ENDCOLOR <<  YELLOW <<this->_darkestSecret << ENDCOLOR << std::endl;
	std::cout << BLUE << "Phone Number : " << ENDCOLOR << YELLOW << this->_phoneNumber << ENDCOLOR << std::endl;
	std::cout << std::endl;
}

std::string	Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string	Contact::getlastName() const
{
	return (this->_lastName);
}

std::string	Contact::getNickname() const
{
	return (this->_nickname);
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

#endif