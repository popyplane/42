#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "style.hpp"

class WrongAnimal
{
	protected:
		string	_type;
	
	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const &rhs );
		virtual ~WrongAnimal();

		WrongAnimal	&operator=( WrongAnimal const &rhs );

		void	makeSound( void ) const;
		string	getType() const;
};

#endif