#include "../inc/Zombie.hpp"

// ZOMBIE PUBLIC FUNCTIONS //////////////////////////////

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::nameZombie( std::string name )
{
	this->name = name;
}

Zombie::Zombie( void )
{
	std::cout << "Zombie constructor called : a zombie is born !!" << std::endl;
}

Zombie::Zombie( std::string name) : name(name)
{
	std::cout << "Zombie constructor called : [ " << this->name << " ] is born." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor called : [ " << this->name << " ] has been slain." << std::endl;	
}