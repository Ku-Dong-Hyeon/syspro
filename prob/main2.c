#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int pid1, pid2;

	pid1=fork();
	pid2=fork();

	if(pid2==0){
		printf("Hello\n");
		exit(1);
	}

	printf("Hello\n");
	return 0;
}
