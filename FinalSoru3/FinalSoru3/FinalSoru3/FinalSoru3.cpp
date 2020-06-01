#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct ogrenci{
	int numara;
	char ad[20];
	float final;
};
void main()
{
	FILE * f1 = fopen("ogrenci.dat", "r+b");
	FILE * f2 = fopen("ogrenciyedek.dat", "w+b");
	struct ogrenci ilkkayit;
	struct ogrenci sonkayit;
	struct ogrenci tut;
	fseek(f1, 0, SEEK_SET);
	fread(&ilkkayit, sizeof(struct ogrenci), 1, f1);
	fseek(f1, sizeof(struct ogrenci) * 99, SEEK_SET);
	fread(&sonkayit, sizeof(struct ogrenci), 1, f1);
	int i = 0;
	for (i; i < 100; i++)
	{
		if (i == 0)
		{
			fseek(f2, 0, SEEK_SET);
			fwrite(&sonkayit, sizeof(struct ogrenci), 1,f2);
			continue;
		}
		if (i == 99)
		{
			fseek(f2, sizeof(struct ogrenci) * 99, SEEK_SET);
			fwrite(&ilkkayit, sizeof(struct ogrenci), 1, f2);
			continue;
		}
		fseek(f1, sizeof(struct ogrenci)* i, SEEK_SET);
		fread(&tut, sizeof(struct ogrenci), 1, f1);
		fseek(f2, sizeof(struct ogrenci)* i, SEEK_SET);
		fwrite(&tut, sizeof(struct ogrenci), 1, f2);
	}
	fclose(f1);
	fclose(f2);
	remove("ogrenci.dat");
	rename("ogrenciyedek.dat", "ogrenci.dat");
}

