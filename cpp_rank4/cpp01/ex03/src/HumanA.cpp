# include "../inc/HumanA.hpp"

// HUMANA PUBLIC FUNCTIONS //////////////////////////////////////////////////////////////////////////////////////////////////
void	HumanA::attack() const
{
	std::cout
		<< name << " attacks with their " << weapon.getType()
		<< std::endl;
}

HumanA::HumanA(std::string givenName, Weapon& uniqueWeapon) : name(givenName), weapon(uniqueWeapon)
{
	std::cout
		<< "HumanA constructor called : [ " << name << " ] is born with [ " << weapon.getType() << " ] as weapon"
		<< std::endl;
}

HumanA::~HumanA()
{
	std::cout
		<< "HumanA destructor called : [ " << name << " ] is dead"
		<< std::endl;
}
