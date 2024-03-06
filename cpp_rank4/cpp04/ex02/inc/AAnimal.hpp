/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:51:53 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 18:50:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "style.hpp"

class AAnimal
{
	protected:
		string	_type;
	
	public:
		AAnimal();
		AAnimal( AAnimal const &rhs );
		virtual ~AAnimal();

		AAnimal	&operator=( AAnimal const &rhs );

		void		virtual makeSound( void ) const = 0;
		string		getType() const;
};

# include "Cat.hpp"
# include "Dog.hpp"

#endif