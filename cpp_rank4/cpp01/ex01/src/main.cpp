# include "../inc/Zombie.hpp"

int main()
{
	Zombie  *horde1 = zombieHorde(3, "Mamache");
	Zombie  *horde2 = zombieHorde(5, "Papache");

	for (int i = 0; i < 3; i++)
		horde1[i].announce();

	for (int i = 0; i < 5; i++)
		horde2[i].announce();

	delete[] horde1;
	delete[] horde2;

	return (0);
}