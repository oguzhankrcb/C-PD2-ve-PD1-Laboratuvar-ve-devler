// Ulama-KU-BU.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>

int buyukunlu_uymayan(char* kelime)
{
	char seperatedwithn[10][50];
	char listkalin[] = { 'A', 'a', 'I', 'ý', 'O', 'o', 'U', 'u' };
	char listince[] = { 'E', 'e', 'Ý', 'i', 'Ö', 'ö', 'Ü', 'ü' };
	char curkelime[50];
	int toplamalinanuzunluk = 0;
	int i;
	int n = 0;
	for (i = 0; i < strlen(kelime); i++)
	{
		if (kelime[i] == ' ')
		{
			int k;
			for (k = 0; k < i; k++)
			{
				seperatedwithn[n][k] = kelime[k];
				toplamalinanuzunluk++;
			}
			
			n++;
		}
		
	}
	printf("bosluk sayisi : %d\n", n);
	int sonkelimeuzunluk = strlen(kelime) - toplamalinanuzunluk + n;
	int q;
	int say = 0;
	for (q = toplamalinanuzunluk; q < strlen(kelime); q++)
	{
		seperatedwithn[n][say] = kelime[q];
		say++;
	}

	int p = 0;
	for (p; p < n - 1; p++)
	{
		int c = 0;
		for (c; c < 50, seperatedwithn[p][c] != '\0'; c++)
		{
			printf("%s\n", seperatedwithn[p][c]);
		}
		
	}
	


	return 0;
}

int ulamasayisi(char* kelime)
{
	char listunlu[] = { 'a', 'A', 'e', 'E', 'I', 'ý', 'i', 'Ý', 'o', 'O', 'Ö', 'ö', 'u', 'U', 'Ü', 'ü' };
	int i;
	int ulamasayisi1 = 0;
	for (i = 0; i < strlen(kelime); i++)
	{
		if (kelime[i] == ' ')
		{
			int j;
			for (j = 0; j < strlen(listunlu); j++)
			{
				if (kelime[i + 1] == listunlu[j])
				{
					int durumabak = 1;
					int k;
					for (k = 0; k < strlen(listunlu); k++)
					{
						if (kelime[i - 1] == listunlu[k] || kelime[i-1] == ',')
						{
							durumabak = 0;
						}
					}
					if (durumabak == 1)
					{
						ulamasayisi1++;
					}
				}
			}
		}
	}
	return ulamasayisi1;
}


void main()
{
	char al[50];
	printf("Kelimeyi giriniz : ");
	gets(al);
	buyukunlu_uymayan(al);
	//printf("Ulama sayisi : %d", ulamasayisi(al));


	getchar();
}

