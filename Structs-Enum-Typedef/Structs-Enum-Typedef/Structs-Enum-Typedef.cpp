// Structs-Enum-Typedef.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

struct ogrenci_bilgileri{
	int vize;
	int finalnotu;
	float ortalama;
	char isim[30];
	struct {
		int gun, ay, yil;
	}dogum_tarih;
};

typedef struct ogrenci_bilgileri ob;

ob ortalamahesap(ob* s)
{
	s->ortalama = s->vize * 0.40 + s->finalnotu * 0.60;


	return *s;
}



void main()
{
	ob ogrenci;
	printf("Ogrenci adini giriniz : ");
	scanf("%s", ogrenci.isim);
	printf("\nOgrenci vize notunu giriniz : ");
	scanf("%d", &ogrenci.vize);
	printf("\nOgrenci final notunu giriniz : ");
	scanf("%d", &ogrenci.finalnotu);
	printf("\nOgrenci dogum tarihi giriniz : ");
	scanf("%d-%d-%d", &ogrenci.dogum_tarih.gun, &ogrenci.dogum_tarih.ay, &ogrenci.dogum_tarih.yil);
	ogrenci = ortalamahesap(&ogrenci);
	printf("\n%s adli ogrencinin ortalamasi : %.2f", ogrenci.isim, ogrenci.ortalama);

	getch();
}
