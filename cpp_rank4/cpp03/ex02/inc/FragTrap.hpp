/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:38:35 by codespace         #+#    #+#             */
/*   Updated: 2024/03/05 17:06:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap();

	public:
		FragTrap( string name );
		FragTrap( FragTrap const &other );
		virtual ~FragTrap();

		FragTrap &operator=( FragTrap const &other );

		void	highFivesGuys( void );
};

std::ostream &operator<<(std::ostream &out, FragTrap const & FragTrap);

#endif