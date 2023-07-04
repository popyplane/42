/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:05:08 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/04 15:42:16 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

/* ------ utils.c ------ */
void	error(void);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

/* -----------------  utils_bonus.c -------------*/
int		get_next_line(char **line);
void	here_doc(char **argv, int argc);
void	parent_here_doc(int *fd);
int		open_file(char *argv, int i);

/* --------------- pipex_bonus.c ----------------*/
void	child_process(char *cmd, char **envp);

#endif