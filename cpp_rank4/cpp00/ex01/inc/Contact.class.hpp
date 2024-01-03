#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "phoneBook.hpp"

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


	public:

		Contact();
		~Contact();

		bool		setContact();
		void		getContact();
};

bool	Contact::_setFirstName()
{
	std::string	buffer;

	std::cout << "First Name: ";
	std::cin >> buffer;
	std::cout << std::endl;
	this->_firstName = buffer;
	std::cout << "First Name set as :" << this->_firstName << std::endl;
	return (true);
}

bool	Contact::_setLastName()
{
	std::string	buffer;

	std::cout << "Last Name: ";
	std::cin >> buffer;
	std::cout << std::endl;
	this->_lastName = buffer;
	std::cout << "Last Name set as :" << this->_lastName << std::endl;
	return (true);
}

bool	Contact::_setNickname()
{
	std::string	buffer;

	std::cout << "Nickname: ";
	std::cin >> buffer;
	std::cout << std::endl;
	this->_nickname = buffer;
	std::cout << "Nickname set as :" << this->_nickname << std::endl;
	return (true);
}

bool	Contact::_setDarkestSecret()
{
	std::string	buffer;

	std::cout << "Darkest Secret: ";
	std::cin >> buffer;
	std::cout << std::endl;
	this->_darkestSecret = buffer;
	std::cout << "Darkest Secret set as :" << this->_darkestSecret << std::endl;
	return (true);
}

bool	Contact::_setPhoneNumber()
{
	std::string	buffer;

	std::cout << "Phone Number: ";
	std::cin >> buffer;
	std::cout << std::endl;
	this->_phoneNumber = buffer;
	std::cout << "Phone Number set as :" << this->_phoneNumber << std::endl;
	return (true);
}


Contact::Contact()
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact destructor called" << std::endl;
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

#endif