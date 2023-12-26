/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:19:44 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/25 22:41:41 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	ft_unset_helper(char *key);

t_err_no	unset_builtin(char **args)
{
	int		i;
	t_err_no	err;

	if (!args[1])
		return (ENO_SUCCESS);
	err = ENO_SUCCESS;
	i = 0;
	while (args[++i])
	{
		if (!check_key(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			err = ENO_GENERAL;
		}
		else
			unset_helper(garbage_collector(extract_key(args[i]), false));
	}
	return (err);
}

static void	ft_unset_helper(char *key)
{
	t_env	*current;
	t_env	*prev;

	prev = NULL;
	current = g_minishell.envlst;
	while (current)
	{
		if (!ft_strcmp(key, current->key))
		{
			if (prev)
				prev->next = current->next;
			else
				g_minishell.envlst = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}