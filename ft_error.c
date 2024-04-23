/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:35:33 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 14:41:22 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	liberator(char **str1, char *str2)
{
	int	i;

	i = 0;
	if (NULL != str2)
		free(str2);
	if (NULL != str1)
	{
		while (NULL != str1[i])
			free(str1[i++]);
		free(str1);
	}
}

/**
 * @brief Prints the Error message and exits
 *
 * @param s addition message info
 * @param status status exit code
 */
void	ft_error(char *s, int status)
{
	perror(s);
	exit(status);
}
//perror("\033[31mError");
