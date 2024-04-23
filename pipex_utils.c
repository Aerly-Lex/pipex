/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:51:02 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 15:22:25 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Locates the path of the command
 *
 * @param cmd
 * @param envp
 * @returns The Path of the Command: char *cmd
 */
static char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*path_testing;

	i = 0;
	while (0 == (ft_strnstr(envp[i], "PATH", 4)))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (NULL != paths[i])
	{
		path_testing = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_testing, cmd);
		free(path_testing);
		if (0 == access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	liberator(paths, NULL);
	return (NULL);
}

void	exec(char *command, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	path = get_path(*cmd, envp);
	if (NULL == path)
	{
		ft_printf("zsh: command not found: %s\n", *cmd);
		exit(127);
	}
	execve(path, cmd, envp);
	perror("execve");
	liberator(cmd, path);
	exit(EXIT_FAILURE);
}

/**
 * @brief
 *
 * @param argv is the file to be opened
 * @param i 0 = READ
 * @param i 1 = WRITE, CREATE, TRUNCATE
 * @param i 2 = WRITE, CREATE, APPEND
 * @return the file value in int
 */
int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (0 == i)
		file = open(argv, O_RDONLY, 0644);
	else if (1 == i)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (2 == i)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (-1 == file)
	{
		ft_printf("zsh: No such file or directory: %s\n", argv);
		exit(EXIT_FAILURE);
	}
	return (file);
}
