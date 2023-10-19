#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{ 
   int fd1, fd2, n;
   char buf[BUFSIZ];
   char* a[BUFSIZ];
   if (argc != 2) { 
      fprintf(stderr,"How to use: %s file1 file2\n",        
               argv[0]); 
      exit(1); 
   }
   if ((fd1 = open(argv[1], O_RDONLY)) ==    -1) {
      perror(argv[1]);
      exit(2); 
   }

   while ((n = read(fd1, buf, BUFSIZ)) > 0) {
      printf("%s",buf);
   	  *a = buf;
	  printf("%s",*a);
   }
   exit(0); 
}
