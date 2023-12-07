#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void alarmHandler();

struct sigaction newact;
struct sigaction oldact;
void sig_alarmhandler(int signo);

int main(void) {
	int i = 1;
	newact.sa_handler = sig_alarmhandler;
	sigfillset(&newact.sa_mask);
	sigaction(SIGALRM,&newact,&oldact);
	alarm(5);
	
	while(1) {
		sleep(1);
		printf("%d second \n",i);
		i++;
	}
	printf("can't start");
}

void sig_alarmhandler(int signo){
	printf("Wake up\n");
}
