/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:25:15 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 18:38:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
		
	public:
		Dog();
		Dog( Dog const &rhs );
		virtual ~Dog();

		Dog     &operator=( Dog const &rhs );

		void	virtual makeSound( void ) const;
}; 

#endif