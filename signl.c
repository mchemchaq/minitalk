
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void bin_to_char(int signum, char c)
{
   if(signum == SIGUSR1)
   {
      c = (c << 1) | 1;
      printf("%c",c);
   } 
   else if(signum == SIGUSR2) 
   {
      c <<= 1;
      printf("%c",c);
   }
}
void sig_handler(int signum, siginfo_t* info, void* context)
{
   static int c = 0;
   (void)context;
   (void)info;
   (void)signum;
   if(signum == SIGUSR2 || signum == SIGUSR2)
      c++;
      
}

int main(void)
{
   struct sigaction sa;
  
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = sig_handler;
   sigaction(SIGUSR1, &sa, NULL);
   while (1)
      pause();
   return (0);
}