// FinalSorulariCevap.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
	char kelimeler[250];
	printf("Bir karakter dizisi giriniz : ");
	cgets(kelimeler);
	int uzunluk = strlen(kelimeler);

	int i = 0;
	int sayac = 0;
	for (i; i < uzunluk; i++)
	{
		if (kelimeler[i] == 'a' && kelimeler[i + 1] == 'k')
			sayac++;
	}


	printf("%d adet ak kelime dizisi bulunmaktadir.", sayac);

	getch();
}



/*int final[70];
int vize[70];
void main()
{
	int i = 0;
	int not;
	for (i; i < 70; i++)
	{
		printf("%d. ogrencinin final notunu giriniz : ", (i +1));
		scanf("%d", &not);
		final[i] = not;
		printf("%d. ogrencinin vize notunu giriniz : ",(i+1));
		scanf("%d", &not);
		vize[i] = not;
	}

	getch();
}*/
/*int diz[13] = { 10,15,3,2,5,16,13,4,6,31,18,20,110 };
int enkucukteksbul(int * dizi)
{
	int i = 0;
	for (i; i < 100; i++)
	{
		int j = i + 1;
		for (j; j < 100; j++)
		{
			if (dizi[i] > dizi[j])
			{
				int gecici = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = gecici;
			}
		}
	}
	int k = 0;
	for (k; k < 100; k++)
	{
		if (dizi[k] % 2 == 1)
			return dizi[k];
	}
	return 0;
}*/


/*void main()
{
	int a = enkucukteksbul(diz);
	//int uzunluk = sizeof(diz) / sizeof(int);

	printf("%d", a);

	getch();
}
*/
