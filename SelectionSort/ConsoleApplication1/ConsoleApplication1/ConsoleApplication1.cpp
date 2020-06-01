#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void main()
{
	int dizi[5] = { 10, 32, 25, 1, 8 };
	int i = 0;
	int gecici;
	for (i; i < 5; i++)
	{
		int j = i + 1;
		for (j; j < 5; j++)
		{
			if (dizi[i] < dizi[j])
			{
				gecici = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = gecici;
			}
		}
	}
	getch();
}