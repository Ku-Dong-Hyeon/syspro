#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void alarmHandler();

int main() {
	int i = 1;
	signal(SIGALRM, alarmHandler);
	alarm(5);
	printf("Loop Start \n");
	while(1) {
		sleep(1);
		printf("%d second \n",i);
		i++;
	}
	printf("can't start");
}

void alarmHandler(int signo){
	printf("Wake up\n");
	exit(0);
}
