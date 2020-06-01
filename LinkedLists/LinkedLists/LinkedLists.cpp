// LinkedLists.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct ogrenciler{
	int yas;
	char isim[25];
	int sinif;
	int sira;
	struct ogrenciler * next;
};

typedef struct ogrenciler node;

node * ListeOlustur()
{
	node * head = (node *)malloc(sizeof(node));
	printf("ogrenci bilglerini giriniz : ");
	scanf("%d %s %d", &head->yas, head->isim, &head->sinif);
	head->sira = 0;

	head->next = NULL;
	return head;
}

node* ListeyeEkle(node * head,int nereye)
{
	node * p, *q,*yeni;
	p = head;
	while (1)
	{
		if (p->sira != nereye && p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		else
		{
			if (p->sira == 0)
			{
				yeni = (node*)malloc(sizeof(node));
				yeni->next = head;
				head = yeni;
				printf("ogrenci bilgilerini giriniz : ");
				scanf("%d %s %d", &yeni->yas, yeni->isim, &yeni->sinif);
				yeni->sira = 0;
				break;
			}

			if (p->sira == nereye)
			{
				yeni = (node*)malloc(sizeof(node));
				q->next = yeni;
				yeni->next = p;
				printf("ogrenci bilgilerini giriniz : ");
				scanf("%d %s %d", &yeni->yas, yeni->isim, &yeni->sinif);
				yeni->sira = nereye;
				break;
			}

			if (p->next == NULL)
			{
				p->next = (node*)malloc(sizeof(node));
				p = p->next;
				printf("ogrenci bilgilerini giriniz : ");
				scanf("%d %s %d", &p->yas, p->isim, &p->sinif);
				p->sira = nereye;
				p->next = NULL;
				break;
			}
		}
	}
	return head;
}

node * ListedenSil(int nereden, node* head)
{
	node * p, *q,*newhead;

	p = head;

	while (p->next != NULL && p->sira != nereden)
	{
		q = p;
		p = p->next;
	}

	if (p->sira == 0)
	{
		newhead = head->next;
		free(head);
		return newhead;
	}
	if (p->sira == nereden && p->next == NULL)
	{
		q->next = NULL;
		free(p);
		return head;
	}

	if (p->sira == nereden)
	{
		q->next = p->next;
		free(p);
		return head;
	}

	return head;
}

void main()
{
	int kactane,sayac=0;
	node * head,*p;

    head = ListeOlustur();

	p = head;

	printf("Kac tane ogrenci kaydedilecek : ");
	scanf("%d", &kactane);
	while (sayac != kactane)
	{
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
			printf("ogrenci bilgilerini giriniz : ");
			scanf("%d %s %d", &p->yas, p->isim, &p->sinif);
			p->sira = sayac + 1;
			p->next = NULL;
		sayac = sayac + 1;
	}

	head = ListeyeEkle(head, 6);

	head = ListedenSil(2, head);
	p = head;

	while (p != NULL)
	{
		printf("Ogrenci bilgileri : %d , %s , %d , %d\n", p->yas, p->isim, p->sinif, p->sira);
		p = p->next;
	}
	getch();
}

