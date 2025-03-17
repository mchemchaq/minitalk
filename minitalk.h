/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:58:28 by mchemcha          #+#    #+#             */
/*   Updated: 2024/05/01 17:51:07 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//printf_fonction
int			ft_printf(const char *s, ...);
int			print_char(char n);
int			print_str(char *c);
int			print_nbr(int n);
//minitalk fonction
void		ft_handle_signal(int signum, siginfo_t *info, void *context);
void		conv_to_bin_send(char s, int pid);
void		lire_msg(char *msg, int pid);
int			ft_atoi(char *str);

#endif