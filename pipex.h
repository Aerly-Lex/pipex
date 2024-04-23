/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:24:54 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 11:22:36 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
// # include <stdio.h> // remove!

# define HELP "\nInvalid arguments - please enter following pattern:\n\
file1 cmd1 | cmd2 > file2\n\n"
# define HELP_BONUS "\nInvalid arguments - please enter one of following pattern:\n\
./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdx file2\n\
./pipex_bonus here_doc LIMITER cmd cmd1 file\n\n"

void		exec(char *command, char **envp);
void		ft_error(char *s, int status);
void		liberator(char **str1, char *str2);
int			open_file(char *argv, int i);

#endif

// fcntl.h =	open
// 			unlink
// unistd.h =	read
// 			write
// 			close
// 			access
// 			pipe
// 			fork
// 			execve
// 			dup
// 			dup2
// sys/wait = 	wait
// 			waitpit
// stdlib.h =	malloc
// 			free
// 			exit
// stdio.h	=	perror
// string.h =	strerror
