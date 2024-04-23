/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:30:18 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 15:27:40 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_args(int argc)
{
	if (5 != argc)
	{
		ft_printf("%s", HELP);
		exit(1);
	}
}

void	child(int *fd, char **argv, char **envp)
{
	int	file;

	file = open_file(argv[1], 0);
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(file);
	close(fd[1]);
	close(fd[0]);
	exec(argv[2], envp);
}

void	parent(int *fd, char **argv, char **envp)
{
	int	file;

	file = open_file(argv[4], 1);
	dup2(file, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(file);
	close(fd[0]);
	close(fd[1]);
	exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;

	process_args(argc);
	if (-1 == pipe(fd))
		ft_error("Pipe error", EXIT_FAILURE);
	pid1 = fork();
	if (0 > pid1)
		ft_error("Fork error", EXIT_FAILURE);
	if (0 == pid1)
		child(fd, argv, envp);
	parent(fd, argv, envp);
	wait(NULL);
	wait(NULL);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

// https://www.rozmichelle.com/pipes-forks-dups/

// int	main(int argc, char **argv, char **envp)
// {
// 	int	fd[2]; // 0 for reading - 1 for writing
// 	int	pid1;
// 	// int	child_status;

// 	process_args(argc, argv);
// 	if (-1 == pipe(fd))
// 		ft_error("Pipe error", EXIT_FAILURE);
// 	if (0 > (pid1 = fork()))
// 		ft_error("Fork error", EXIT_FAILURE);
// 	if (0 == pid1)
// 		child(fd, argv, envp);
// 	// wait(&child_status);
// 	// if (0 != child_status)
// 	// 	ft_error("Child process ended due error\n");
// 	// if (0 > (pid2 = fork()))
// 	// 	ft_error("Fork2 error", EXIT_FAILURE);
// 	// if (0 == pid2)
// 	parent(fd, argv, envp);
// 	wait(NULL);
// 	wait(NULL);
// 	close(fd[0]);
// 	close(fd[1]);
// 	return (0);
// }

// void	child_process(char *argv, char **envp)
// {
// 	pid_t	pid;
// 	int		fd[2];

// 	if (pipe(fd) == -1)
// 		ft_error("Pipe Error", EXIT_FAILURE);
// 	pid = fork();
// 	if (pid == -1)
// 		ft_error("fork Error", EXIT_FAILURE);
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		exec(argv, envp);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		waitpid(pid, NULL, 0);
// 	}
// }
