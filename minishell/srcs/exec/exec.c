/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:55:18 by baptistevie       #+#    #+#             */
/*   Updated: 2023/12/19 19:02:57 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_err_no	exec_node(t_node *tree, t_bool piped)
{
	t_err_no	status;

	if (!tree)
		return (ENO_GENERAL);
	if (tree->type == N_PIPE)
		exec_pipe(tree);
	else if (tree->type == N_OR)
	{
		status = exec_node(tree->left, false);
		if (status == ENO_SUCCESS)
			return;
		return (exec_node(tree->right, false));
	}
	else if (tree->type == N_AND)
	{
		status = exec_node(tree->left, false);
		if (status == ENO_SUCCESS)
			return (exec_node(tree->right, false));
		return;
	}
	else
		exec_cmd(tree, piped);
}

static t_err_no	exec_pipe_child(t_node *tree)
{
	t_err_no	status;
	int			fd[2];
	pid_t		pid_l;
	pid_t		pid_r;
	
	g_minishell.sigint_child = true;
	pipe(fd);
	pid_l = fork();
	if (pid_l == 0)
		exec_pipe_child(tree->left, fd, BRANCH_L);
	else
	{
		(close(pfds[0]), close(pfds[1]),
			waitpid(pid_l, &status, 0), waitpid(pid_r, &status, 0));
		g_minishell.signint_child = false;
		return (get_exit_status(status));
	}
	return (ENO_GENERAL);
}

static t_err_no	exec_pipe_child(t_node *node, int fd[2], t_ast_branch branch)
{
	int	status;

	if (branch == BRANCH_L)
	{
		close(pfds[0]);
		dup2(pfds[1], STDOUT_FILENO);
		close(pfds[1]);
	}
	else if (branch == BRANCH_R)
	{
		close(pfds[1]);
		dup2(pfds[0], STDIN_FILENO);
		close(pfds[0]);
	}
	status = exec_node(node, true);
	(clean_minishell(), exit(status));
}

t_err_no	ft_get_exit_status(t_err_no status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}