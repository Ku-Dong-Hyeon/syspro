#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAXARG 100

int main() {
	char args[MAXARG];
	int pid, status;

	printf("Pls input cmd : ");
	fgets(args, MAXARG - 1, stdin);

	if (args[0] != '\n') {
		args[strcspn(args, "\n")] = '\0';
		pid = fork();
		if (pid == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if(pid == 0) {
			if (strcmp(args, "ls -al") == 0) {
				printf("[%d] Parent process start\n", getpid());
				system("ls -al");
				printf("SUCCESS\n");
			}
			else if (strcmp(args, "wc test.txt &") == 0) {
				printf("[%d] Parent process start\n", getpid());
				printf("[%d] child process start\n", getpid());
				system("wc test.txt &\n");
			}
			else {
				printf("[%d] Parent process start\n", getpid());
				printf("Parent process end\n");
				printf("Exit\n");
			}
			exit(EXIT_SUCCESS);
		}
		else {
			waitpid(pid, &status, 0);
		}
	}
	return 0;
}
