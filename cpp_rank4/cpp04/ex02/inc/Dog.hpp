/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:25:15 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:43:12 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog( Dog const &rhs );
		virtual ~Dog();

		Dog			&operator=( Dog const &rhs );

		void		virtual makeSound( void ) const;
}; 

#endif