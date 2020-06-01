#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#include <string.h>
struct ogrenci{
	char adsoyad[30];
	char yas[10];
	char no[5];
}ob;

FILE * dosya;
int kayitsayisi(FILE * dosya)
{
	int filenoyual = fileno(dosya);
	int dosyaboyutu = filelength(filenoyual);
	
	return (dosyaboyutu / sizeof(ob));
}

void dosyayaz()
{
	dosya = fopen("data.dat", "r+b");
	if (dosya == NULL)
	{
		dosya = fopen("data.dat", "w+b");
		printf("lutfen ogrencinin adini giriniz : ");
		gets(ob.adsoyad);
		printf("lutfen ogrencinin nosunu giriniz : ");
		gets(ob.no);
		printf("lutfen ogrencinin yasini giriniz :");
		gets(ob.yas);
		fwrite(&ob, sizeof(ob), 1, dosya);
		fclose(dosya);
	}
	else
	{
		fseek(dosya, kayitsayisi(dosya) * sizeof(ob), SEEK_SET);
		printf("lutfen ogrencinin adini giriniz : ");
		gets(ob.adsoyad);
		printf("lutfen ogrencinin nosunu giriniz : ");
		gets(ob.no);
		printf("lutfen ogrencinin yasini giriniz :");
		gets(ob.yas);
		fwrite(&ob, sizeof(ob), 1, dosya);
		fclose(dosya);
	}
}
void Listele()
{
	dosya = fopen("data.dat", "r+b");
	int kaysay = kayitsayisi(dosya);
	int i = 0;
	for (i; i < kaysay; i++)
	{
		fseek(dosya, i* sizeof(ob), SEEK_SET);
		fread(&ob, sizeof(ob), 1, dosya);
		printf("Adi soyadi : %s\nNumarasi : %s\nYasi : %s\n---------------------------------------\n", ob.adsoyad, ob.no, ob.yas);
	}
	fclose(dosya);
}
void Ara(const char * ogrenciadi)
{
	dosya = fopen("data.dat", "r+b");
	int kaysay = kayitsayisi(dosya);
	int i = 0;
	int buldumu = 0;
	for (i; i < kaysay; i++)
	{
		fseek(dosya, sizeof(ob)* i, SEEK_SET);
		fread(&ob, sizeof(ob), 1, dosya);
		if (strcmp(ogrenciadi, ob.adsoyad) == 0)
		{
			printf("Aranan Ogrencinin Nosu : %s , Yasi : %s", ob.no, ob.yas);
			buldumu = 1;
			break;
		}
	}

	if (buldumu == 0)
	{
		printf("Aranan kan bulunamadi");
	}
}
void NoDuzelt()
{
	char ogad[100], newno[10];
	printf("Aranacak ogrencinin adini giriniz : ");
	gets(ogad);
	printf("Yeni ogrenci numarasini giriniz : ");
	gets(newno);
	dosya = fopen("data.dat", "r+b");
	int kaysay = kayitsayisi(dosya);
	int i = 0;
	for (i; i < kaysay; i++)
	{
		fseek(dosya, i * sizeof(ob), SEEK_SET);
		fread(&ob, sizeof(ob), 1, dosya);
		if (strcmp(ogad, ob.adsoyad) == 0)
		{
			strcpy(ob.no, newno);
			fseek(dosya, i * sizeof(ob), SEEK_SET);
			fwrite(&ob, sizeof(ob), 1, dosya);
			printf("Ogrenci bulundu ve numarasi basariyla degistirildi...");
			fclose(dosya);
			return;
		}
	}
	printf("Ogrenci bulunamadigi icin islem gerceklestirilemedi...");
	fclose(dosya);
}
void TamSil()
{
	FILE *yenidosya = fopen("data2.dat", "w+b");
	dosya = fopen("data.dat", "r+b");
	int kaysay = kayitsayisi(dosya);
	int i = 0;
	int buldu = 0;
	for (i; i < kaysay; i++)
	{
		fseek(dosya, sizeof(ob)*i, SEEK_SET);
		fread(&ob, sizeof(ob), 1, dosya);
		if (ob.no[0] == '5' && ob.no[1] == '3')
		{
			buldu++;
		}
		else
		{
			fseek(yenidosya, (i-buldu)  * sizeof(ob), SEEK_SET);
			fwrite(&ob, sizeof(ob), 1, dosya);
		}
	}
	if (buldu > 0)
	{
		remove("data.dat");
		rename("data2.dat", "data.dat");
	}
	else
	{
		remove("data2.dat");
	}
}
void main()
{
	//dosyayaz();
	Listele();
	//NoDuzelt();
	getch();
}