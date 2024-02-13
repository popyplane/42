#include "../inc/Zombie.hpp"

int main( void )
{
    Zombie  bob("Bob");
    Zombie  *tom = newZombie("Tom");

    bob.announce();
    randomChump("Joe");
    tom->announce();

    delete tom;

    return ( 0 );
}