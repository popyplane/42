/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:31:54 by codespace         #+#    #+#             */
/*   Updated: 2024/03/06 22:28:59 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "style.hpp"

class Brain
{
    private:
        string  _ideas[100];
        void    _setIdeas(void);

	public:
		Brain();
		Brain( Brain const &rhs );
		virtual ~Brain();

		Brain     &operator=( Brain const &rhs );
};

#endif