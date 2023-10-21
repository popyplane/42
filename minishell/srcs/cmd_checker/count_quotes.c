/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:46:06 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/10/21 15:43:47 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_buffer_info	fill_buffer_info(char *buffer, t_buffer_info *b_info)
{
	size_t	i;
	size_t	len;

	if (!buffer)
		return (-1); // valeur de retour d'erreur a verifier
	len = strlen(buffer);
	i = -1;
	while (++i < len)
	{
		if (buffer[i] == '\'' && !(b_info->doub_q_nb % 2))
			count_simp_q++;
		if (buffer[i] == '\"' && !(b_info->simp_q_nb % 2))
			count_doub_q++;
		if (buffer[i] == '|' && !is_inside_quotes(b_info))
			b_info->pipe_nb++;
		if (!is_inside_quotes(b_info) && (buffer[i] == '<' || buffer[i] == '>'))
		{
			b_info = check_io_modifier(buffer[i], buffer[i + 1], b_info);
			if (buffer[i] == buffer[i + 1])
				i++;
		}	
	}
	return (b_info);
}

static t_bool	is_inside_quotes(t_buffer_info *b_info)
{
	return ((b_info->simp_q_nb % 2 || b_info->doub_q_nb % 2));
}

t_buffer_info	check_io_modifier(char c1, char c2, t_buffer_info b_info)
{
	if (c1 == '<')
	{
		if (c1 == c2)
			b_info->io_info->heredoc_mode = true;
		else
			b_info->io_info->redir_in = true;
	}
	if (c1 == '>')
	{
		if (c1 == c2)
			b_info->io_info->append_mode = true;
		else
			b_info->io_info->redir_out = true;
	}
	return (b_info);
}



// t_bool	check_quotes(char *str)
// {
// 	t_bool	simp_q;
// 	t_bool	doub_q;

// 	if (!str)
// 		return (false);
// 	simp_q = check_pair(str, '\'');
// 	doub_q = check_pair(str, '\"');
// 	return (simp_q && doub_q);
// }

// static t_bool	check_pair(char *str, char c)
// {
// 	size_t	i;
// 	size_t	len;
// 	int		count_q;
	
// 	if (!str)
// 		return (false);
// 	len = ft_strlen(str);
// 	i = 0;
// 	count_q = 0;
// 	while (i < len)
// 	{
// 		if (str[i] == c)
// 			count_q++;
// 	}
// 	return (!(count_q % 2));
// }