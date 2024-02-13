# include "../inc/Weapon.hpp"

// PUBLIC MEMBER FUNCTIONS ///////////////////////////////////////////////////
void	Weapon::setType( std::string newType )
{
	type = newType;
}

std::string	Weapon::getType( void ) const
{
	return ( type );
}

Weapon::Weapon( std::string newType ) : type(newType)
{
	std::cout
		<< "Weapon constructor called : " << type << " has been built"
		<< std::endl;
}

Weapon::~Weapon()
{
	std::cout
		<< "Weapon destructor called : " << this->type << " has been destroyed"
		<< std::endl;
}