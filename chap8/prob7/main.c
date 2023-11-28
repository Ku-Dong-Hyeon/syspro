#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int flag = 0;
	int a;
	
	if(argc<2)
		fp = stdin;

	while((a = getopt(argc, argv, "eugip")) != -1) {
		switch(a) {
			case 'e':
				if (argc == 2) {
					flag = 1;
					break;
				}
				if (argc == 3) {
					flag = 2;
					break;
				}
			case 'u':
				flag = 3;
				break;
			case 'g':
				flag = 4;
				break;
			case 'i':
				flag = 5;
				break;
			case 'p':
				flag = 6;
				break;
		}
	}

	if(flag == 1) {
		char **ptr;
		extern char **environ;
		for (ptr = environ; *ptr != 0; ptr++) {
			printf("%s \n", *ptr);
		}
		exit(0);
	}
	else if(flag == 2) {
		char *ptr;
		ptr = getenv("PATH");
		printf("PATH = %s \n",ptr);

		exit(0);
	}
	else if(flag == 3) {
		printf("My Realistic User ID : %d(%s)\n",getuid(),getpwuid(getuid())->pw_name);
		printf("My Valid User ID : %d(%s)\n",geteuid(),getpwuid(geteuid())->pw_name);
		exit(0);
	}
	else if(flag == 4) {
		printf("My Realistic Group ID : %d(%s)\n",getgid(),getgrgid(getgid())->gr_name);
		printf("My Valid Group ID : %d(%s)\n",getegid(),getgrgid(getegid())->gr_name);
		exit(0);
	}
	else if(flag == 5) {
		printf("my process number : [%d] \n",getpid());
		exit(0);
	}
	else if(flag == 6) {
		printf("my parent's process number : [%d] \n",getppid());
		exit(0);
	}
}

