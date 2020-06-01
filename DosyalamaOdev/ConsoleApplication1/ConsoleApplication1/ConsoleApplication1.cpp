// ConsoleApplication1.cpp : Defines the entry point for the console application.
//



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#include <string.h>
struct ogrenci
{
	char k;
	char num[10];
	char adsoyad[30];
	char tel[16];
} ogrkay;
FILE *dosya;

int i, kaysay, say;
long kayit_yer;
char cev, c;

int ksay(void)
{
	return ((filelength(fileno(dosya)) / sizeof(struct ogrenci)));
}
void kalicisilturkcell(void)
{
	FILE * newkalici = fopen("ren.dat", "w+b");
	dosya = fopen("ogrenci.dat", "r+b");
	int sayi = ksay();
	int i = 0;
	int buldumu = 0;
	for (i; i < sayi; i++)
	{
		fseek(dosya, i * sizeof(struct ogrenci), SEEK_SET);
		fread(&ogrkay, sizeof(struct ogrenci), 1, dosya);
		if (ogrkay.tel[0] == '5' && ogrkay.tel[1] == '3')
		{
			buldumu++;
		}
		else
		{
			fseek(newkalici, (i-buldumu) * sizeof(struct ogrenci), SEEK_SET);
			fwrite(&ogrkay, sizeof(struct ogrenci), 1, newkalici);
		}
	}
	fclose(dosya);
	fclose(newkalici);
	if (buldumu > 0)
	{
		remove("ogrenci.dat");
		rename("ren.dat", "ogrenci.dat");
	}
	else
	{
		remove("ren.dat");
	}
}
void duzelt(void)
{
	dosya = fopen("ogrenci.dat", "r+b");
	char duzeltilecek[] = " ";
	char buldu = 0;
	char dsay = 0;
	printf("\nDüzeltilmesi gereken numaranýn sahibini giriniz: ");
	gets(duzeltilecek);
	kaysay = ksay();
	for (int i = 0; i<kaysay; i++)
	{
		fseek(dosya, (i*sizeof(struct ogrenci)), SEEK_SET);
		fread(&ogrkay, sizeof(struct ogrenci), 1, dosya);
		if (ogrkay.k == '*' && !strcmp(ogrkay.adsoyad, duzeltilecek))
		{
			printf("%-10s %-30s %-16s", ogrkay.num, ogrkay.adsoyad, ogrkay.tel);
			printf("\nBu kaydý mý düzelteceksiniz (E/H)");
			char sec = getch();
			if (sec == 'E' || sec == 'e')
			{
				buldu = 1;
				dsay++;
				say++;
				printf("\nYeni numara giriniz: ");
				gets(ogrkay.tel);
				fseek(dosya, (i*sizeof(struct ogrenci)), SEEK_SET);
				fwrite(&ogrkay, sizeof(struct ogrenci), 1, dosya);
			}
		}
	}
	if (buldu)
	{
		printf("\nDüzeltilen Kayit Sayisi= %d", dsay);
	}
	else
		printf("\nDüzeltilecek kayit bulunamadi...");
	fclose(dosya);
	getch();
}
void kayit_ekle(void)
{
	dosya = fopen("ogrenci.dat", "r+b");
	if (dosya == NULL)
		dosya = fopen("ogrenci.dat", "w+b");

	system("cls");
	fflush(stdin);
	printf("Numara.....:");
	gets(ogrkay.num);
	printf("Ad Soyad ..:");
	gets(ogrkay.adsoyad);
	printf("Tel........:");
	gets(ogrkay.tel);
	printf("Girilen Bilgiler Dogru mu? [E/H]");
	cev = getche();
	if (cev == 'E' || cev == 'e')
	{
		ogrkay.k = '*';
		fseek(dosya, filelength(fileno(dosya)), SEEK_SET);
		fwrite(&ogrkay, sizeof(struct ogrenci), 1, dosya);
	}

	fclose(dosya);
}
void baslik(void)
{
	system("cls");
	if (dosya == NULL) printf("Dosya acilamadi");
	printf("%-10s %-30s %-16s \n\n", "NUMARA", "AD SOYAD", "TELEFON");
	say = 0;
}
void listele(void)
{
	dosya = fopen("ogrenci.dat", "rb");
	baslik();
	kaysay = ksay();
	for (int i = 0; i<kaysay; i++)
	{
		fseek(dosya, (i*sizeof(struct ogrenci)), SEEK_SET);
		fread(&ogrkay, sizeof(struct ogrenci), 1, dosya);
		if (ogrkay.k == '*')
		{
			say++;
			printf("%-10s", ogrkay.num);
			printf("%-30s", ogrkay.adsoyad);
			printf("%-16s\n", ogrkay.tel);
			if (say == 20)
			{
				printf("Diger sayfaya gecmek icin bir tusa basiniz");
				getch();
				baslik();
			}
		}
	}
	printf("\nToplam Kayit Sayisi= %d", kaysay);
	printf("\n\nListelenecek kayitlar bitti...");
	fclose(dosya);
	getch();
}
void ara(void)
{
	dosya = fopen("ogrenci.dat", "rb");
	char aranan[] = " ";	char buldu = 0;	char arasay = 0;
	printf("\nBulunmasý istenen ismi giriniz: ");	gets(aranan);
	kaysay = ksay();
	for (int i = 0; i<kaysay; i++)
	{
		fseek(dosya, (i*sizeof(struct ogrenci)), SEEK_SET);
		fread(&ogrkay, sizeof(struct ogrenci), 1, dosya);
		if (ogrkay.k == '*' && !strcmp(ogrkay.adsoyad, aranan))
		{
			buldu = 1;			arasay++;
			say++;
			if (arasay == 1)
				baslik();
			printf("%-10s", ogrkay.num);	printf("%-30s", ogrkay.adsoyad);	printf("%-16s\n", ogrkay.tel);
		}
	}
	if (buldu)
	{
		printf("\nToplam Kayit Sayisi= %d", arasay);
		printf("\n\nListelenecek kayitlar bitti...");
	}
	else
		printf("\nAranan kayit bulunamadi...");
	fclose(dosya);
	getch();
}
void sil(void)
{
	dosya = fopen("ogrenci.dat", "r+b");
	char aranan[] = " ";
	char buldu = 0;
	char silsay = 0;
	printf("\nSilinmesi istenen ismi giriniz: ");
	gets(aranan);
	kaysay = ksay();
	for (int i = 0; i<kaysay; i++)
	{
		fseek(dosya, (i*sizeof(struct ogrenci)), SEEK_SET);
		fread(&ogrkay, sizeof(struct ogrenci), 1, dosya);
		if (ogrkay.k == '*' && !strcmp(ogrkay.adsoyad, aranan))
		{
			buldu = 1;
			silsay++;
			say++;
			ogrkay.k = '-';
			fseek(dosya, (i*sizeof(struct ogrenci)), SEEK_SET);
			fwrite(&ogrkay, sizeof(struct ogrenci), 1, dosya);
		}
	}
	if (buldu)
	{
		printf("\nSilinen Kayit Sayisi= %d", silsay);
	}
	else
		printf("\nAranan kayit bulunamadi...");
	fclose(dosya);
	getch();
}
void getir(void)
{
	dosya = fopen("ogrenci.dat", "r+b");
	char aranan[] = " ";
	char buldu = 0;
	char gerigetirilensay = 0;
	printf("\nGeri Getirilmesi istenen ismi giriniz: ");
	gets(aranan);
	kaysay = ksay();
	for (int i = 0; i<kaysay; i++)
	{
		fseek(dosya, (i*sizeof(struct ogrenci)), SEEK_SET);
		fread(&ogrkay, sizeof(struct ogrenci), 1, dosya);
		if (ogrkay.k == '-' && !strcmp(ogrkay.adsoyad, aranan))
		{
			buldu = 1;
			gerigetirilensay++;
			say++;
			ogrkay.k = '*';
			fseek(dosya, (i*sizeof(struct ogrenci)), SEEK_SET);
			fwrite(&ogrkay, sizeof(struct ogrenci), 1, dosya);
		}
	}
	if (buldu)
	{
		printf("\nGeri getirilen Kayit Sayisi= %d", gerigetirilensay);
	}
	else
		printf("\nAranan kayit bulunamadi...");
	fclose(dosya);
	getch();
}
int main()
{
	do
	{
		system("cls");
		printf("1-Bilgi girisi \n2-Bilgi Listeleme \n3-Ara \n4-Sil \n5-Getir \n6-Düzelt \n7-Cikis \n\nSecim:");
		c = getche();
		if (c == '1') kayit_ekle();
		if (c == '2') listele();
		if (c == '3') ara();
		if (c == '4') sil();
		if (c == '5') getir();
		if (c == '6') duzelt();
		if (c == '7') kalicisilturkcell();
		if (c == '8') exit(0);

	} while (c != '8');
	getch();
	return 0;
}
