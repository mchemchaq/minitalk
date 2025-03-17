/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:57:55 by mchemcha          #+#    #+#             */
/*   Updated: 2024/05/02 16:28:06 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conv_to_bin_send(char s, int pid)
{
	int	i;
	int	i_b;
	int	v;

	i_b = 7;
	while (i_b >= 0)
	{
		i = 0;
		if ((s >> i_b) & 1)
			v = kill(pid, SIGUSR1);
		else
			v = kill(pid, SIGUSR2);
		if (v == -1)
		{
			write(2, "error\n", 6);
			exit(1);
		}
		usleep(800);
		i_b--;
	}
}

void	lire_msg(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		conv_to_bin_send(msg[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		if (pid <= 0 || pid > 99998)
		{
			write(1, "error\n", 6);
			exit(1);
		}
		lire_msg(str, pid);
	}
	else
		write(1, "Error entre pid et message\n", 26);
}
