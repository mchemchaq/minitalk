/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:18:48 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/04 23:40:20 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <sys/signal.h>

void sig_handler(int signum, siginfo_t* info, void* context)
{
   static int curr = 0;
   static char c = 0;
   (void)context;
   (void)info;
   
    if(signum == SIGUSR2)
        curr = 0;
    else 
        curr = 1;
    c = (c >> 1) | 1;
    if (curr == 8)
    {
        printf("%c", c);
        c = 0;
        curr = 0;
        
    }
}

int main()
{
    struct sigaction sa;
    int pid = getpid();
    
    printf("PID = %d\n", pid);
    sa.sa_sigaction = &sig_handler;
    sa.sa_flags = SA_SIGINFO;
    if(sigaction(SIGUSR1, &sa, NULL) == -1)
        exit(1);
    if(sigaction(SIGUSR2, &sa, NULL) == -1)
        exit(1);
    while(1)
    {
        pause();
    }
}
// #include <unistd.h>
// #include <signal.h>
// #include <stdio.h>

// void bin_to_char(int signum, char c)
// {
//    if(signum == SIGUSR1)
//    {
//       c = (c << 1) | 1;
//       printf("%c",c);
//    } 
//    else if(signum == SIGUSR2) 
//    {
//       c <<= 1;
//       printf("%c",c);
//    }
// }
// void sig_handler(int signum, siginfo_t* info, void* context)
// {
//    static int c = 0;
//    (void)context;
//    (void)info;
//    (void)signum;
//    if(signum == SIGUSR2 || signum == SIGUSR2)
//       c++;
      
// }

// int main()
// {
//    struct sigaction sa;
//    int pid = getpid();
  
//    printf("PID : %d ", pid);
//    sigemptyset(&sa.sa_mask);
//    sa.sa_flags = SA_SIGINFO;
//    sa.sa_sigaction = sig_handler;
//    sigaction(SIGUSR1, &sa, NULL);
//    while (1)
//       pause();
//    return (0);
// }