/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:44:41 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/29 15:49:35 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein = -1)
		error();
	dup2(fd[1], STDOUT_FILENO);  // on remplace la sortie standart (STDOUT) par fd[0]
	dup2(filein, STDIN_FILENO);  // on donne le filein comme entree
	// ferme fd[0] pourquoi??
	// execute cmd1
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY, O_CREAT, O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);		//ici ca va encore mais apres???
	// close fd[1] ?????
	// execute cmd2
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid = -1)
			error();
		if (pid == 0)
			child_process(argv, envp, fd);
		wait(NULL);
		parent_process(argv, envp, fd);
	}
}