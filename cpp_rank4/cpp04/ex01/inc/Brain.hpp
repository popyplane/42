/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:31:54 by codespace         #+#    #+#             */
/*   Updated: 2024/03/06 17:53:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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