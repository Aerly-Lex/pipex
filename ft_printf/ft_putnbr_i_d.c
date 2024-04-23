/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:35:55 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 15:29:01 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	negative(int *n)
{
	*n *= -1;
	return (ft_putchar('-'));
}

int	ft_putnbr_i_d(int n, char *base, int base_len)
{
	int	arr[20];
	int	counter;
	int	len;

	counter = 0;
	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
		len += negative(&n);
	else if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		arr[counter] = base[n % base_len];
		n /= base_len;
		counter++;
	}
	len += counter;
	while (counter--)
		ft_putchar(arr[counter]);
	return (len);
}
