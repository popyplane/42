/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:21:23 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/19 18:44:38 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_parse_err(t_parse_err_type type)
{
	g_minishell.parse_err.type = type;
}

void	handle_parse_err(void)
{
	t_parse_err_type	type;
	t_token_type		token_type;
	char				**types;

	types = (char *[]){"T_STR", "|", "&&", "||", 
		"<", ">", ">>", "<<", "newline"};
	type = g_minishell.parse_err.type;
	(void)token_type;
	(void)types;
	if (type)
	{
		if (type == E_SYNTAX)
		{
			if (!g_minishell.curr_token)
				token_type = T_NL;
			else
				token_type = g_minishell.curr_token->type;
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd(types[token_type], 2);
			ft_putstr_fd("'\n", 2);
			g_minishell.exit_s = 258;
		}
		ft_clear_ast(&g_minishell.ast);
		ft_bzero(&g_minishell.parse_err, sizeof(t_parse_err));
	}
}