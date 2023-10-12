#include <stdio.h>
#include <string.h>
#include "copy.h"
char line[5][MAXLINE];
char longest[MAXLINE];

int main(){
	int count = 0;
	
	while(count < 5) {
		if(fgets(line[count],MAXLINE,stdin) == NULL) {
			break;
		}
		longest[count] = strlen(line[count]);
		count++;
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<4-i; j++){
			if(longest[j]<longest[j+1]){
				char temp[MAXLINE];
				strncpy(temp, line[j], MAXLINE);
				strncpy(line[j],line[j+1],MAXLINE);
				strncpy(line[j+1],temp,MAXLINE);

				int templen = longest[j];
				longest[j] = longest[j+1];
				longest[j+1] = templen;
			}
		}
	}

	for(int i = 0; i<5; i++)
		printf("%s", line[i]);

	return 0;
}
