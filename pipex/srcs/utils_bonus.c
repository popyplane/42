/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:08:58 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/06/26 16:58:04 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	get_next_line(char **line)
{
	char		*buffer;
	char		c;
	ssize_t		reader;
	int			i;

	reader = 0;
	i = 0;
	buffer = malloc(10000 * sizeof(char));
	if (!buffer)
		return (-1);
	reader = read(0, &c, 1);
	while (reader && c != '\n' && c != '\0')
	{
		buffer[i] = c;
		i++;
		reader = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (reader);
}

void	here_doc(int argc, char **argv)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc < 6)
		error();
	if (pipe(fd) == -1)
		error();
	pid = fork(); //gerer pid = -1  !! 25 lignes
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
				&& ft_strlen(line) == ft_strlen(argv[2]) + 1)
				exit(EXIT_SUCCESS);
			ft_putstr_fd(line, fd[1]);
		}
	}
	else 
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		error();
	return (file);
}