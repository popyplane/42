/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:58:04 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 18:36:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
		
	public:
		Cat();
		Cat( Cat const &rhs );
		virtual ~Cat();

		Cat     &operator=( Cat const &rhs );

		void	virtual makeSound( void ) const;
};

#endif