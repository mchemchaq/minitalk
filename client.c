/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:57:55 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/03 22:18:05 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>
#include <signal.h>

// void sig_handler(int num,siginfo_t *info, void *content)
// {
//    static int i;
// }
 
void conv_to_bin_send(char s, int pid)
{
   int i;
   int i_b;

   i_b = 7;
   while(i_b >= 0 )
   {
      i = 0;
      if((s >> i_b) & 1)
         kill(pid, SIGUSR1);
      else
         kill(pid, SIGUSR2);
      usleep(800);
      i_b--;
   }
}
void lire_msg(char *msg,int pid)
{
   int i;
   i = 0;
   while(msg[i])
   {
      conv_to_bin_send(msg[i], pid);
      i++;
   }
}

int main(int ac, char **av)
{
   int pid;
   char *str;
   if(ac == 3)
   {
      pid = atoi(av[1]);
      str = av[2];
      if(pid <= 0)
         exit(1);
      lire_msg(str, pid);
      // sa.sa_flags = 
         // use sigemptyset to empty 
      
      
   }
}
// int main(void)
// {
//    struct sigaction sa;
  
//    sigemptyset(&sa.sa_mask);
//    sa.sa_flags = SA_RESTART | SA_SIGINFO;
//    sa.sa_handler = SIG_IGN;
//    sigaction(SIGINT, &sa, NULL);
//    while (1)
//       sleep(1);
//    return (0);
// }
 