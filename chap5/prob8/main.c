#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd, id;
	char c;
	char savedText[10][100];

	if(argc < 2){
		fprintf(stderr, "How to use : %s file\n",argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDWR)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	
	printf("Total Line : %d\n");

	exit(0);
}
