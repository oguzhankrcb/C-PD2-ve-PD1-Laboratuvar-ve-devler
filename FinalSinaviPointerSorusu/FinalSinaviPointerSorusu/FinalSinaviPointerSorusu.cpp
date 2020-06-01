// FinalSinaviPointerSorusu.cpp : Defines the entry point for the console application.
//
#include <stdio.h>


void main()
{// BASLANGIC 0x00F1F9A4
	int i, a, *ptr;
	int dizi[] = { 22,15,9,-2,11,90,52,10,3,210,-5,33 };
	ptr = dizi;
	printf("%p\n", ptr);
	for (i = 3; i < 6; i++)									// i = 3 ----> a = -2 , *ptr = 9
	{														// i = 4 ----> a = 52, *ptr = 90
		a = *(ptr + i);										// i = 5 ----> a = -5, F1F9C8
		printf("%d \n", a);
		ptr = &ptr[i - 1];
		if (i < 5) continue;
		printf("%p\n", ptr);

	}

	ptr = &dizi[2];
	a = (ptr + 1)[2];
	printf("%d", a);

	getchar();
}
