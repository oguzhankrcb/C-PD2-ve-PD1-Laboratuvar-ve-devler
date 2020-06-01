#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
	int dizi[5] = { 10, 8, 25, 32, 1 };
	int i = 0;
	int gecici;
	for (i; i < 4; i++)
	{
		int j = 0;
		for (j; j < 5 - i; j++)
		{
			if (dizi[j] < dizi[j + 1])
			{
				gecici = dizi[j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = gecici;
			}
		}
	}
	getch();
}

