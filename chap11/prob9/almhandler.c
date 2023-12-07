#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void alarmHandler(int signo);

struct sigaction act;

int main() {
	int i = 1;
	act.sa_handler = alarmHandler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	
	if (sigaction(SIGALRM,&act,NULL)==-1){
		exit(0);
	}

	alarm(5);
	
	while(1) {
		sleep(1);
		printf("%d second \n",i);
		i++;
	}
	printf("Can't start\n");
	return 0;
}

void alarmHandler(int signo){
	printf("Wake up\n");
	exit(0);
}
