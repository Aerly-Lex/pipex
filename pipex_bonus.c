/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:29:16 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 15:24:31 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_args(int argc)
{
	if (5 > argc)
	{
		ft_printf("%s", HELP_BONUS);
		exit(1);
	}
}

void	children(char *argv, char **envp)
{
	int	pid;
	int	fd[2];

	if (-1 == pipe(fd))
		ft_error("Pipe error", EXIT_FAILURE);
	pid = fork();
	if (0 > pid)
		ft_error("Fork error", EXIT_FAILURE);
	if (0 == pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		// waitpid(pid, NULL, 0);
	}
}

int	here_doc(char *argv)
{
	int		fd[2];
	char	*buffer;
	int		limit_len;
	int		bytes_read;

	buffer = malloc(sizeof(char) * 1001);
	limit_len = ft_strlen(argv);
	if (-1 == pipe(fd))
		ft_error("Pipe error", EXIT_FAILURE);
	while (1)
	{
		write(1, "pipe heredoc>", 14);
		bytes_read = read(0, buffer, 1000);
		buffer[bytes_read] = '\0';
		if (0 == ft_strncmp(buffer, argv, limit_len) && \
			'\n' == buffer[limit_len])
			break ;
		write(fd[1], buffer, bytes_read);
	}
	free(buffer);
	close(fd[1]);
	return (fd[0]);
}

int	file_handling(int *infile, int *outfile, int argc, char **argv)
{
	int	i;

	if (0 == ft_strncmp("here_doc", argv[1], 8))
	{
		i = 3;
		*infile = here_doc(argv[2]);
		*outfile = open_file(argv[argc - 1], 2);
	}
	else
	{
		i = 2;
		*infile = open_file(argv[1], 0);
		*outfile = open_file(argv[argc - 1], 1);
	}
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	process_args(argc);
	i = file_handling(&infile, &outfile, argc, argv);
	dup2(infile, 0);
	dup2(outfile, 1);
	close(infile);
	close(outfile);
	while (i < (argc - 2))
		children(argv[i++], envp);
	exec(argv[i], envp);
	return (0);
}

// < infile sort | uniq -c | sort -r | head -3 > outfile
// ./pipex_bonus infile  "sort"  "uniq -c"  "sort -r"  "head -3"  outfile
// ls << END | wc -c >> outfile

// UNDER Construction
// This is a function where I'm trying to implement here_doc
// with a temporary file instead of a pipe
// int	here_doc(char *argv)
// {
// 	int		infile;
// 	int		fd[2];
// 	char	*buffer;
// 	int		bytes_read = 1;
// 	char result[1000] = "";
// 	infile = open_file(argv, 1);
// 	if (-1 == pipe(fd))
// 		ft_error("Pipe error", EXIT_FAILURE);
// 	dup2(infile, 0);
// 	close(infile);
// 	dup2(fd[1], 1);
// 	close(fd[1]);
// 	close(fd[0]);
// 	buffer = malloc(sizeof(char *) * 1000);
// 	while (1)
// 	{
// 		readline()
// 		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
// 		buffer[bytes_read] = '\0';
// 		ft_printf("%s", ft_strjoin(result, buffer));
// 		if (0 == ft_strncmp(result, "END", 3))
// 			break ;
// 	}
// 	return (infile);
// }
