#include <stdio.h>
int main( )
{
   alarm(5);
   printf("Loop start \n");
   int i = 1;
   while (1) {
      sleep(1);
      printf("%d second \n",i);
	  i++;
   }
   printf("Alarm clock\n");
}

