#include <stdio.h>

struct menu {
	int id;
	char name[20];
	char category[20];
	int date;
	int stock;
};

int main(int argc, char* argv[]){
	struct menu rec;
	FILE *fp;
	fp = fopen("db.dat","w");
	printf("%s %-7s %-4s %-4s %-4s\n","id", "name", "category", "expired date", "stock");
	while(scanf("%d %s %s %d %d",&rec.id,rec.name,rec.category,&rec.date,&rec.stock)==5)
		fprintf(fp, "%d %s %s %d %d\n",rec.id,rec.name,rec.category,rec.date,rec.stock);
	fclose(fp);

	return 0;
}
