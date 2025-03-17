/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:17:48 by mchemcha          #+#    #+#             */
/*   Updated: 2024/05/01 17:51:31 by mchemcha         ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (SIZE_MAX - (str[i] - 48)) / 10 && sign > 0)
			return (-1);
		else if (result > (SIZE_MAX - (str[i] - 48)) / 10 && sign < 0)
			return (0);
		result = (result * 10 + str[i] - 48);
		i++;
	}
	return (result *= sign);
}
