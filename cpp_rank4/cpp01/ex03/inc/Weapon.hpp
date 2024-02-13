#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		void			setType( std::string newType );
		std::string		getType( void ) const;
	
		Weapon( std::string newType );
		~Weapon();
};


# endif