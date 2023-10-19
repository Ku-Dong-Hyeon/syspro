#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAXLINE 80

int main(int argc, char *argv[]){
	FILE *fp;
	int c;
	int line = 0;
	char buffer[MAXLINE];
	int flag = 0;
	int a;

	if(argc<2)
		fp=stdin;
	
	while((a = getopt(argc, argv, "n")) != -1){
		switch(a) {
			case 'n':
				flag = 1;
				break;
		}
	}

	if(flag==1) {
		for(int i=2;i<argc;i++) {
			fp=fopen(argv[i],"r");
			while (fgets(buffer,MAXLINE,fp) != NULL) {
				line ++;
				printf("%3d %s",line,buffer);
			}
			fclose(fp);
		}
	}
	else {
		for(int i=1;i<argc;i++) {
			fp=fopen(argv[i],"r");
			c = getc(fp);

			while(c != EOF){
				putc(c,stdout);
				c = getc(fp);
			}
			fclose(fp);
		}
	}
	return 0;
}

