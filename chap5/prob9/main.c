#include <stdio.h>
#define MAXLINE 80
int main(int argc, char *argv[]){
	FILE *fp;
	int c;
	int line = 0;
	char buffer[MAXLINE];
	char* a[5000]={0,};

	if(argc < 2)
		fp = stdin;
	else
		fp = fopen(argv[1],"r");
		while(fgets(buffer,MAXLINE,fp) != NULL){
			a[line] = buffer;
			line++;
			printf("%s",buffer);
			printf("             ");
			printf("%s\n",a[line]);
		}
		for(int i=0; i<line; i++){
			printf("%s\n",a[i]);
		}
	fclose(fp);
	return 0;
}
