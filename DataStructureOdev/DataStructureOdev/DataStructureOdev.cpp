// DataStructureOdev.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

struct yasaklikelimeler{
	char* kelime = "";
};

typedef struct yasaklikelimeler yk;

void main()
{

	char *icerik;
	icerik = (char*)malloc(80000);
	char kelimeler[30000][30];
	FILE * myfile = fopen("hamlet.txt", "r");
	fseek(myfile, 0, SEEK_END);
	int boyut = ftell(myfile);
	int countofsentence = 0;
	printf("%d characters found in the hamlet.txt.\n", boyut);
	fseek(myfile, 0, SEEK_SET);
	int kaldigimyer = 0;
	int i = 0;
	
	for (i; i < boyut; i++)
	{
		char q = fgetc(myfile);
		if (q != '\0')
		{
			icerik[i] = q;
		//	printf("%c", q);
		}
	}
	fclose(myfile);
	char* paparazi = strtok(icerik, " ,.-\n");
	while (paparazi != NULL)
	{
		
		//printf("%d. sentence : %s\n", kaldigimyer, paparazi);
		//Sleep(1000);
		int k = 0;
		for (k; k < strlen(paparazi); k++)
		{
			kelimeler[kaldigimyer][k] = paparazi[k];
			if (k + 1 == strlen(paparazi))
			{
				kelimeler[kaldigimyer][k + 1] = '\0';
			}
		}
		

		paparazi = strtok(NULL, " ,.-\n");

		kaldigimyer++;
	}

	int p = 0;
	yk ykelime[30000];
	for (p; p < kaldigimyer; p++)
	{
		
		int kelsayisi = 1;
		int m = p + 1;
		for (m; m < kaldigimyer; m++)
		{
			int durum = 1;
			int l = 0;
			for (l; l < 30000; l++)
			{
				if (!strcmp(ykelime[l].kelime, kelimeler[m]))
				{
					durum = 0;
					break;
				}
			}
			if (durum == 1)
			{
				if (!strcmp(kelimeler[p], kelimeler[m]))
				{
					kelsayisi++;

				}
			}
				
			
			
		}
	

		int durum = 1;
		int l = 0;
		for (l; l < 30000; l++)
		{
			if (!strcmp(ykelime[l].kelime, kelimeler[p]))
			{
				durum = 0;
				break;
			}
		}
		if (durum == 1)
		{
			printf("Kelime : %s ve Sayisi : %d\n", kelimeler[p], kelsayisi);
		}

		ykelime[p].kelime = kelimeler[p];
		
		//
		

		//Sleep(1000);
		
	}
	
	

	getch();
}
