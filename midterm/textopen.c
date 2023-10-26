#include <stdio.h>
#define MAXLINE 80
int main(int argc, char *argv[]){
	FILE *fp;
	int line = 0;
	char buffer[MAXLINE];

	if(argc<2)
		fp = stdin;
	else
		fp = fopen(argv[1],"r");


	while(fgets(buffer,MAXLINE,fp) != NULL) {
		line++;
		if(line < 3){
			for(int i=0;i<2;i++){
				line++;
				printf("%s",buffer);
			}
			break;
		}
	}
}
