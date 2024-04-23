/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:04:42 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 15:29:04 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h> // va_list, va_start, va_arg, va_end

int	ft_printf(const char *str, ...);
int	ft_putnbr_i_d(int n, char *base, int base_len);
int	ft_putnbr_u(unsigned int n, char *base, int base_len);
int	ft_putnbr_p(void *p, char *base, int base_len);
int	ft_putchar(char c);

#endif
