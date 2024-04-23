/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:30:23 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/12 15:29:02 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(void *p, char *base, int base_len)
{
	unsigned long	arr[256];
	unsigned long	counter;
	unsigned long	n;
	unsigned long	len;

	counter = 0;
	n = (unsigned long)p;
	len = (write(1, "0x", 2));
	if (n == 0)
		len += ft_putchar('0');
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
