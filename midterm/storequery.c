#include <stdio.h>

struct menu {
	int id;
	char name[20];
	char category[20];
	int date;
	int stock;
};

int main(int argc, char* argv[]) {
	struct menu rec;
	int c = 0;
	printf("0: list of all goods, 1: list of available goods ) ");
	scanf("%d\n",&c);
	if(c==0){
		FILE *fp = fopen("db.dat","r");
		printf("%s %-7s %-4s %-4s %-4s\n","id","name","category","expired date","stock");
		while(fscanf(fp,"%d %s %s %d %d",&rec.id,rec.name,rec.category,&rec.date,&rec.stock)==5)
			printf("%d %6s %3s %3d %3d\n",rec.id,rec.name,rec.category,rec.date,rec.stock);
		fclose(fp);
	}
	else if (c==1){
		FILE *fp = fopen("db.dat","r");
		printf("%s %-7s %-4s %-4s %-4s\n","id","name","category","expired date","stock");
		while(fscanf(fp,"%d %s %s %d %d",&rec.id,rec.name,rec.category,&rec.date,&rec.stock)==5)
			if(rec.date >= 2023 && rec.stock > 0){
				printf("%d %6s %3s %3d %3d\n",rec.id,rec.name,rec.category,rec.date,rec.stock);
			}
		fclose(fp);
	}
	return 0;
}
