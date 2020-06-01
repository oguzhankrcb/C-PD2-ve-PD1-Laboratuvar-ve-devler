
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct kelimeler{
	int uzunluk;
	char kelime[100];
	struct kelimeler * next;
};
typedef struct kelimeler node;
char * longestwordinlist(node* head)
{
	int enbuyuk = 0;
	char *enbuyukisim;
	while (head != NULL)
	{
		if (head->uzunluk > enbuyuk)
		{
			enbuyuk = head->uzunluk;
			enbuyukisim = head->kelime;
		}
		head = head->next;
	}
	return enbuyukisim;
}
void main()
{
	node * head,*p;
	head = (node*)malloc(sizeof(node));
	p = head;
	char sentence[500];
	printf("Give me a sentence : ");
	gets(sentence);
	int i, kontrol = 0, kontrol2 = 0;
	for (i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] == ' ')
		{
			if (kontrol == 0)
			{
				kontrol = 1;
				int uzunluk = i - kontrol2;
				int j;
				int say = 0;
				for (j = kontrol2; j < i; j++)
				{
					head->kelime[say] = sentence[j];
					say++;
				}
				head->kelime[say] = '\0';
				kontrol2 = i + 1;
				head->uzunluk = uzunluk;
				head->next = NULL;
			}
			else
			{
				p->next = (node*)malloc(sizeof(node));
				p = p->next;
				int uzunluk = i - kontrol2;
				int j;
				int say = 0;
				for (j = kontrol2; j < i; j++)
				{
					p->kelime[say] = sentence[j];
					say++;
				}
				p->kelime[say] = '\0';
				kontrol2 = i + 1;
				p->uzunluk = uzunluk;
				p->next = NULL;
			}
		}
		else if (strlen(sentence) - 1 == i)
		{
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
			int uzunluk = (i + 1) - kontrol2;
			int j;
			int say = 0;
			for (j = kontrol2; j < (i + 1); j++)
			{
				p->kelime[say] = sentence[j];
				say++;
			}
			p->kelime[say] = '\0';
			kontrol2 = i + 1;
			p->uzunluk = uzunluk;
			p->next = NULL;
		}
	}
	char * longestword = longestwordinlist(head);
	printf("%s", longestword);
	getch();
}







//**************************************************************************************************************************

/*struct node{
	int sayi;
	struct node* bag;
};
typedef struct node node;
node* CreateList(int a[5])
{
	int i = 0;
	for (i; i < 5; i++)
	{
		int k = i + 1;
		for (k; k < 5; k++)
		{
			if (a[i] > a[k])
			{
				int temp = a[i];
				a[i] = a[k];
				a[k] = temp;
			}
		}
	}
	node * head, *p;
	head = (node*)malloc(sizeof(node));
	int j = 0;
	p = head;
	for (j; j < 5; j++)
	{
		if (j == 0)
		{
			head->sayi = a[j];
			head->bag = NULL;
		}
		else
		{
			p->bag = (node*)malloc(sizeof(node));
			p = p->bag;
			p->sayi = a[j];
			p->bag = NULL;
		}
	}
	return head;
}
void main()
{
	node * head,*p;
	int b[5] = { 15, 32, 21, 68, 22 };
	head = CreateList(b);
	p = head;
	while (p != NULL)
	{
		printf("%d ", p->sayi);
		p = p->bag;
	}
	getch();
}*/

//**************************************************************************************************************************

/*struct ogrencibilgi{
	int number;
	char name[30];
	float finalgrade;
	struct ogrencibilgi * next;
};
typedef struct ogrencibilgi node;
void main()
{
	node * head,*p,*newstr;
	head = (node*)malloc(sizeof(node)); // head i�in haf�zadan yer a�t�k
	int i,k;
	printf("How many students do u have to enter informations : ");
	scanf("%d", &i); // ka� ��renci girilece�ini i de�i�kenine al�yoruz
	p = head; // gezici pointerimizi head'e aktar�yoruz
	for (k = 0; k < i; k++)
	{
		if (k == 0) // k = 0 ise daha bilgi girilmemi�tir bu y�zden head i�in bilgi girdiriyoruz
		{
			printf("Type the information about %d. student order by name, number, finalgrade : ", (k+1));
			scanf("%s %d %f", head->name, &head->number, &head->finalgrade);
			head->next = NULL;
		}
		else // de�ilse di�er nodelere giri� yap�yoruz
		{
			p->next = (node*)malloc(sizeof(node)); // yeni node i�in yer a��yoruz
			p = p->next; // pointerimizi yeni nodeye getiriyoruz
			printf("Type the information about %d. student order by name, number, finalgrade : ", (k + 1));
			scanf("%s %d %f", p->name, &p->number, &p->finalgrade); // yeni nodeye ��renci bilgilerini yazd�r�yoruz.
			p->next = NULL; // en son girdi�imiz node'nin bir sonraki nodesini null yap�yoruz ki listenin sonuna gelindi�ini anlayabilelim.
		}	
	}
	p = head;
	int say = 1;
	while (p != NULL) // listeyi g�r�nt�leme fonksiyonu i�in
	{
		printf("%s named student's number is %d and finalgrade is %.2f\n", p->name, p->number, p->finalgrade);
		p = p->next;
	}
	getch();
}*/