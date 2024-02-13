# include "../inc/HumanB.hpp"

// HUMANB PUBLIC FUNCTIONS //////////////////////////////////////////////////////////////////////////////////////////////////
void	HumanB::attack() const
{
	if (weapon)
		std::cout
			<< name << " attacks with their " << weapon->getType()
			<< std::endl;
	else
		std::cout
			<< name << " attacks with their hands !!"
			<< std::endl;
}

void    HumanB::setWeapon( Weapon& newWeapon )
{
	if (weapon)
		delete weapon;
	weapon = &newWeapon;
}

HumanB::HumanB( std::string givenName ) : name(givenName), weapon(NULL)
{
	std::cout
		<< "HumanB constructor called : [ " << name << " ] is born"
		<< std::endl;
}

HumanB::~HumanB()
{
	std::cout
		<< "HumanB destructor called : [ " << name << " ] is dead"
		<< std::endl;
}