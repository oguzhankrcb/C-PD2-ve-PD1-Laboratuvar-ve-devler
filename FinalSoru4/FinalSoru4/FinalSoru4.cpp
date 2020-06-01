// FinalSoru4.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
float RakamOrt(int*);
void main()
{
	int a, *p;
	printf("Sayi giriniz : ");
	scanf("%d", &a);
	p = &a;
	float al = RakamOrt(p);
	printf("\n%.2f", al);
	getch();
}
float RakamOrt(int * gelens)
{
	int sayi = *gelens;
	if (sayi > 999 && sayi < 10000)
	{
		int binincib = sayi / 1000;
		int yuzlerbasamagi = sayi % 1000;
		int yuzlerb = yuzlerbasamagi / 100;
		int onlarbasamagi = yuzlerbasamagi % 100;
		int onlarb = onlarbasamagi / 10;
		int birlerb = onlarbasamagi % 10;
		return (birlerb + binincib + yuzlerb + onlarb) / 4;
	}
	else
	{
		return (float)sayi;
	}
}
