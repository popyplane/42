
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();

	public:
		ScavTrap( string name );
		ScavTrap( ScavTrap const &other );
		virtual ~ScavTrap();

		ScavTrap &operator=(ScavTrap const &other);

		void	attack( const string& target );
		void	guardGate();
};

std::ostream &operator<<(std::ostream &out, ScavTrap const & scavTrap);

#endif