/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:43:43 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 15:29:06 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n, char *base, int base_len)
{
	unsigned int	arr[256];
	unsigned int	counter;
	unsigned int	len;

	counter = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		arr[counter] = base[n % base_len];
		n /= base_len;
		counter++;
	}
	len = counter;
	while (counter--)
		ft_putchar(arr[counter]);
	return (len);
}
