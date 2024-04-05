/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:17:48 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/05 23:13:10 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_char(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	print_nbr(int n)
{
	int	nb;
	int	i;

	i = 0;
	nb = n;
	if (n == -2147483648)
	{
		i += print_str("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		i += print_char('-');
		nb *= -1;
	}
	if (nb < 10)
		i += print_char(nb + '0');
	else
	{
		i += print_nbr(nb / 10);
		i += print_nbr(nb % 10);
	}
	return (i);
}

int	print_str(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		write (1, "(null)", 6);
		return (i += 6, i);
	}
	while (c[i])
	{
		write (1, &c[i], 1);
		i++;
	}
	return (i);
}
