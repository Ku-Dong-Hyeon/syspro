#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define MAXLINE 10
#define MAXLINE_LEN 100
int main(int argc, char *argv[]){
	FILE *fp;
	char savedText[MAXLINE][MAXLINE_LEN];
	char buffer[MAXLINE_LEN];
	int line;
	
	fp = fopen("test.txt","r");
	if(fp == NULL){
		printf("FILE OPEN ERROR\n");
		return 1;
	}
	
	int count = 0;

	printf("File read success\n");
	
	while(count < MAXLINE && fgets(buffer,sizeof(buffer),fp) != NULL){
		strncpy(savedText[count],buffer,MAXLINE_LEN);
		count++;
	}

	printf("Total Line : %d\n",count);

	printf("You can choose 1 ~ 4 Line\n");
	printf("Pls 'Enter' the line to select : ");
	scanf("%d",&line);

	if (line >= 1 && line <= count){
		printf("%s",savedText[line-1]);
	}else{
		printf("Wrong Line Number\n");
	}
	fclose(fp);

	return 0;
}
