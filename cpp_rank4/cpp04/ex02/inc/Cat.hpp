/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:58:04 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:43:10 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat( Cat const &rhs );
		virtual ~Cat();

		Cat     &operator=( Cat const &rhs );

		void	virtual makeSound( void ) const;
};

#endif