#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX 100
int main(int argc, char *argv[])
{ 
   char* n[50];
   char* name;

   FILE* fp;
   int cnt = 0;

   fp = fopen("test.txt","r");

   if(fp == NULL){
	   fprintf(stderr, "File Open Error!\n");
	   exit(1);
   }

   for(int i=0; i<5; i++){
	   name = (char*)malloc(sizeof(char) * MAX);
	   fgets(name, MAX, fp);
	   n[i] = name;
   }

   for(int i = 4; i >= 0; i--)
	   printf("%s",n[i]);

   for(int i = 4; i >= 0; i--)
	   free(n[i]);

   fclose(fp);

   return 0;
}
