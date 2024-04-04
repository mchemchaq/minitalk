#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main()
{
   // & = and;
   // | = or;
   // << = left shift
   // >> = rigtht shift

   int x = 6; // 6 = 0000 0110
   int y = 12; // 12 = 0000 1100
   int z = 0; // 0 = 0000 0000

   z = x & y;
   // 6  = 0000 0110
   // 12 = 0000 1100
   // z  = 0000 0100 = 4;
   printf("z  = x & y = %d\n", z);
   z = x | y;
   // 6  = 0000 0110
   // 12 = 0000 1100
   // z  = 0000 1110 = 14;
   printf("z  = x | y = %d\n", z);
   z = x ^ y;
   // 6  = 0000 0110
   // 12 = 0000 1100
   // z  = 0000 1110 = 14;
   printf("z  = x ^ y = %d\n", z);
   z = 255 >> 1;
   // 6  = 01111 1111
   // 12 = 0000 1100
   // z  = 0000 0011 = 127;
   printf("z  = x >> y = %d\n", z);
   z = 0x8 << 1;
   // 6  = 0000 0110
   //    1 1111 1110
   // 12 = 0000 1100
   // z = 6  = 10000000 = 254;
   printf("z  = x << y = %d\n", z);
   return(0);
}