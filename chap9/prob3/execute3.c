#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int child, pid, status;
	pid = fork();
	if(pid == 0) {
		fprintf(stderr, "%s:Unexecutable\n",argv[1]);
	}
	else {
		printf("[%d] child process %d end \n",getpid(),pid);
		printf("\t end code %d \n",status>>8);
	}
}
