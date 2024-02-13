#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;

	public:
		void	attack() const;

		HumanA(std::string givenName, Weapon& uniqueWeapon);
		~HumanA();
};

#endif