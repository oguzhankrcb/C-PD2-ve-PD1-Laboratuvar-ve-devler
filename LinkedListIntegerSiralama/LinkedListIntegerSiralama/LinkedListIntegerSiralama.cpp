// LinkedListIntegerSiralama.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

struct bilgiler{
	int no;
	struct bilgiler *next;
};
typedef struct bilgiler node;

void ListeOlustur(node**head)
{
	*head = (node*)malloc(sizeof(node));
	node *p = *head;
	printf("Numarayi Giriniz : ");
	scanf("%d", &p->no);
	p->next = NULL;

}
void ListEkleKdenBSirala(node**head,int no)
{
	int yedek;
	node *p, *q,*yeni;
	p = *head;
	if (no <= p->no)
	{
		yeni = (node*)malloc(sizeof(node));
		yeni->no = no;
		yeni->next = *head;
		*head = yeni;
		return;
	}
	else
	{
		while (p != NULL)
		{
			if (no <= p->no)
			{
				yeni = (node*)malloc(sizeof(node));
				yeni->no = no;
				q->next = yeni;
				yeni->next = p;
				return;
			}
			q = p;
			p = p->next;
		}
		q->next = (node*)malloc(sizeof(node));
		q = q->next;
		q->no = no;
		q->next = NULL;
	}

}
void ListGoster(node **head)
{
	node *p = *head;
	while (p != NULL)
	{
		printf("%d ", p->no);
		p = p->next;
	}
	printf("- List");
}
void main()
{
	srand(time(NULL));
	node *head;
	ListeOlustur(&head);
	int i = 0;
	for (i; i < 20; i++)
	{
		int k = rand() % 100;
		ListEkleKdenBSirala(&head, k);
	}
	ListGoster(&head);
	getch();
}