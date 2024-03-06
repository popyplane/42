/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:51:53 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:22:48 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "style.hpp"

class Animal
{
	protected:
		string	_type;
	
	public:
		Animal();
		Animal( Animal const &rhs );
		virtual ~Animal();

		Animal	&operator=( Animal const &rhs );

		void	virtual makeSound( void ) const;
		string	getType() const;
};

# include "Cat.hpp"
# include "Dog.hpp"

#endif