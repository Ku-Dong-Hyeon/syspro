#include <stdio.h>
#include <string.h>
#include "copy.h"
char line[MAXLINE];
char longest[MAXLINE];

int main(){
	int len;
	int max;
	max = 0;

	while(fgets(line,MAXLINE,stdin) != NULL) {
		len = strlen(line);

		if(len > max) {
			max = len;
			copy(line, longest);
		}
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<4-i; j++){
			if(longest[j]<longest[j+i]){
				char temp[MAXLINE];
				strcpy(temp, line[j]);
				strcpy(line[j],line[j+1]);
				strcpy(line[j+1],temp);

				int templen = longest[j];
				longest[j] = longest[j+1];
				longest[j+1] = templen;
			}
		}
	}

	if (max > 0)
		printf("%s", longest);

	return 0;
}
