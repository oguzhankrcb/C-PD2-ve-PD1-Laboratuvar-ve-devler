// PerfectNumbers.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>


void main()
{
	int n = 0;

	printf("Lutfen n sayisini giriniz : ");
	scanf("%d", &n);
	int i = 1;
	
	for (i; i <= n; i++)
	{
		int t = 0;
		int k = 1;

		for (k; k < i; k++)
		{
			if (i % k == 0)
			{
				t += k;

			}
		}

		if (t == i)
		{

			printf("Mukemmel sayi burda : %d\n", i);
		}

	}

	getch();
}
