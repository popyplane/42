/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:48:36 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/06/26 17:16:41 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void    error(void)
{
    perror("\033[31mError");
    exit(EXIT_FAILURE);
}

char    *find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path;
    char    *part_path;
    int     i;

    i = -1;
    while (envp[++i])
        if (ft_strnstr(envp[i], "PATH", 4))
            paths = ft_split(envp[i] + 5, ':');
    i = -1;
    while (paths[++i])
    {
        part_path = ft_strjoin(paths[i], "/");
        path = ft_strjoin(part_path, cmd);
        free(part_path);
        if (access(path, X_OK) != -1)
            return (path);
        free(path);
    }
    while (--i >= 0)
        free(paths[i]);
    free(paths);
    return (NULL);
}

void    execute(char *argv, char **envp)
{
    char    **cmd;
    char    *path;
    int     i;

    cmd = ft_split(argv, ' ');
    path = find_path(cmd[0], envp);
    if (!path)
    {
        i = -1;
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
        error();
    }
    if (execve(path, cmd, envp) == -1)
        error();
}
