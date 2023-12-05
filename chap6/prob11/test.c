#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*,char*,struct stat*, char);

int main(int argc, char **argv){
	DIR *dp;
	char *dir;
	struct stat st;
	struct dirent *d;
	char path[BUFSIZ+1];

	if(argc>2)
		dir = argv[2];
	else if(argc==2){
		if(argv[1][0]=='-')
			dir=".";
		else
			dir=argv[1];
	}
	else if(argc==1)
		dir=".";
	
	if((dp= opendir(dir))==NULL)
		perror(dir);

	while ((d=readdir(dp))!=NULL){
	 	sprintf(path,"%s/%s",dir,d->d_name);
		if(lstat(path,&st)<0)
			perror(path);
		else
			printStat(path,d->d_name,&st,argv[1][1]);
	}
    	closedir(dp);
    	exit(0);
}

void printStat(char *pathname, char *file, struct stat *st,char argv){
	printf("%5ld ",st->st_blocks);
	if(argv=='i')
		printf("%lu ",st->st_ino);
	char fileType = type(st->st_mode);
	printf("%c%s ", fileType,perm(st->st_mode));
	printf("%3ld ",st->st_nlink);

	struct passwd *pw = getpwuid(st->st_uid);
	struct group *gr = getgrgid(st->st_gid);

	if (pw != NULL)
		printf("%s ", pw->pw_name);
	else
		printf("%ld", st->st_uid);

	if (gr != NULL)
		printf("%s ", gr->gr_name);
	else
		printf("%ls", st->st_gid);

	printf("%9d ",st->st_size);
	printf("%.12s ",ctime(&st->st_mtime)+4);

	if(argv=='i') {
		if (fileType == 'd')
			printf("%s/\n", file);
		else
			printf("%s\n",file);
	}
	else if(argv=='p') {
		if (fileType == 'd')
			printf("%s/\n", file);
		else
			printf("%s\n",file);
	}
	else if(argv=='Q') {
		if (fileType == 'd')
			printf("\"%s\"\n", file);
		else
			printf("%s\n",file);
	}
	else
		printf("%s\n",file);
}

char type(mode_t mode){
	if (S_ISREG(mode))
		return('-');
	if (S_ISDIR(mode))
		return('d');
	if (S_ISCHR(mode))
		return('c');
	if (S_ISBLK(mode))
		return('b');
	if (S_ISLNK(mode))
		return('l');
	if (S_ISFIFO(mode))
		return('p');
	if (S_ISSOCK(mode))
		return('s');
}

char* perm(mode_t mode){
	static char perms[10];
	strcpy(perms, "---------");

	for(int i=0;i<3;i++){
		if(mode & (S_IRUSR >> i*3))
			perms[i*3]='r';
		if(mode & (S_IWUSR>>i*3))
			perms[i*3+1]='w';
		if(mode & (S_IXUSR>>i*3))
			perms[i*3+2]='x';
	}
	return(perms);
}
