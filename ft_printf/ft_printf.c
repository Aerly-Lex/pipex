/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:11:17 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/01/05 15:39:59 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(2, &c, 1));
}

static int	ft_putstr(char *s)
{
	int	len;
	int	tmp;

	len = 0;
	if (s == NULL)
	{
		tmp = write(2, "(null)", 6);
		if (tmp == -1)
			return (-1);
		return (6);
	}
	while (*s != '\0')
	{
		tmp = write(2, s, 1);
		if (tmp == -1)
			return (-1);
		s++;
		len++;
	}
	return (len);
}

static int	convert(va_list *args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putnbr_p(va_arg(*args, void *), "0123456789abcdef", 16));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_i_d(va_arg(*args, int), "0123456789", 10));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int), "0123456789", 10));
	else if (c == 'x')
		return (ft_putnbr_u(va_arg(*args, int), "0123456789abcdef", 16));
	else if (c == 'X')
		return (ft_putnbr_u(va_arg(*args, int), "0123456789ABCDEF", 16));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (i == -1)
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		printed;
	int		tmp;

	count = 0;
	printed = 0;
	va_start(args, str);
	while (str[count] != '\0')
	{
		if (str[count] != '%')
			tmp = ft_putchar(str[count++]);
		else
		{
			tmp = convert(&args, str[count + 1]);
			count += 2;
		}
		if (tmp == -1)
			return (-1);
		printed += tmp;
	}
	va_end(args);
	return (printed);
}

// #include <stdio.h>
// int	main()
// {
// 	int len = 0;
// // 	// int s1 = 0;
// // 	// int s2 = 0;
// 	printf("Hello World %i", 600);
// 	len = printf("Hello World %i", 600);
// 	printf("len:%d\n", len);
// 	len = ft_printf("Hello World %i", 600);
// 	ft_printf("len:%d\n", len);

// // 	// printf("\ni \tand \td\n");
// // 	// len = printf("%i\t%d\n", 0, -8527413);
// // 	// printf("len:%d\n", len);
// // 	// len = ft_printf("%i\t%d\n", 0, -8527413);
// // 	// printf("len:%d\n", len);

// // 	// int	voidling = 42;
// // 	// unsigned int u = 4561387;
// // 	// printf("\np \tand \tu\n");
// // 	// len = printf("%p\t%u\n", &voidling, u);
// // 	// printf("len:%d\n", len);
// // 	// len = ft_printf("%p\t%u\n", &voidling, u);
// // 	// printf("len:%d\n", len);

// // 	// unsigned int x = 4194512153;
// // 	// unsigned int X = -94512740;
// // 	// printf("\nx \tand \tX\n");
// // 	// len = printf("%x\t%X\n", x, X);
// // 	// printf("len:%d\n", len);
// // 	// len = ft_printf("%x\t%X\n", x, X);
// // 	// printf("len:%d\n", len);
// 	return (0);
// }
