/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:14:17 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/05 23:08:23 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_check(const char *s, int *i, int *c, va_list ap)
{
	if (s[(*i)] == '%' && s[(*i) + 1])
	{
		if (s[(*i) + 1] == 'd' || s[(*i) + 1] == 'i')
			*c += print_nbr(va_arg(ap, int));
		(*i)++;
		return (0);
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, s);
	while (s[i])
	{
		if (ft_check(s, &i, &c, ap))
		{
			print_char(s[i]);
			c++;
		}
		if (s[i])
			i++;
	}
	va_end(ap);
	return (c);
}
