#include <stdio.h>
#include <string.h>
struct menu {
	int id;
	char name[20];
	char category[20];
	int date;
	int stock;
};

int main(int argc, char* argv[]) {
	struct menu rec;
	char c[20];
	char x[20] = "coffee";
	char y[20] = "tea";
	printf("input goods category ] ");
	scanf("%s\n",c);
	if(strcmp(c,x)==0){
		FILE *fp = fopen("db.dat","r");
		printf("%s %-7s %-4s %-4s %-4s\n","id","name","category","expired date","stock");
		while(fscanf(fp,"%d %s %s %d %d",&rec.id,rec.name,rec.category,&rec.date,&rec.stock)==5)
			if(rec.category == x){
				printf("%d %6s %3s %3d %3d\n",rec.id,rec.name,rec.category,rec.date,rec.stock);
			}
		fclose(fp);
	}
	else if (strcmp(c,y)==0){
		FILE *fp = fopen("db.dat","r");
		printf("%s %-7s %-4s %-4s %-4s\n","id","name","category","expired date","stock");
		while(fscanf(fp,"%d %s %s %d %d",&rec.id,rec.name,rec.category,&rec.date,&rec.stock)==5)
			if(rec.category == y){
				printf("%d %6s %3s %3d %3d\n",rec.id,rec.name,rec.category,rec.date,rec.stock);
			}
		fclose(fp);
	}
	else {
		printf("not found goods category : '%s'",c);
	}
	return 0;
}
