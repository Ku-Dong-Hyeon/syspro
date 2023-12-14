#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void intHandler(int signo);
int pid;

int main(){
	signal(SIGINT,intHandler);

	int child, status;
	pid = fork();

	if(pid==0){
		while(1){
			sleep(1);
			printf("Process [1] Execution\n");
		}
		exit(0);
	}
	else {
		printf("Parent process (PID %d) waiting for the child process (PID %d) to exit...\n", getpid(), pid);
		waitpid(pid,&status,0);
		printf("Parent process (PID %d) resumed execution after child process (PID %d) exited.\n", getpid(), pid);
		printf("parent Killed\n");
	}
	return 0;
}

void intHandler(int signo){
	int status;
	printf("Interrupt signal received in the parent process (PID %d).\n", getpid());
	kill(pid,SIGKILL);
	printf("Parent process (PID %d) waiting for the child process (PID %d) to exit...\n", getpid(), pid);
	waitpid(pid, &status, 0);
	printf("Parent process (PID %d) resumed execution after child process (PID %d) exited.\n", getpid(), pid);
	printf("Interrupt to child\n");
	printf("child Killed\n");
	exit(0);
}
