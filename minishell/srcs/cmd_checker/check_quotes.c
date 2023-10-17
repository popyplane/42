/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:46:06 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/10/17 17:17:59 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * check_quotes() checks if all quotes are by pair
 * 
 * returns
*/

static t_bool	check_pair(char *str, char c);

t_bool	check_quotes(char *str)
{
	t_bool	simp_q;
	t_bool	doub_q;

	if (!str)
		return (false);
	simp_q = check_pair(str, '\'');
	doub_q = check_pair(str, '\"');
	return (simp_q && doub_q);
}

static t_bool	check_pair(char *str, char c)
{
	size_t	i;
	size_t	len;
	int		count_q;
	
	if (!str)
		return (false);
	len = ft_strlen(str);
	i = 0;
	count_q = 0;
	while (i < len)
	{
		if (str[i] == c)
			count_q++;
	}
	return (!(count_q % 2))
}