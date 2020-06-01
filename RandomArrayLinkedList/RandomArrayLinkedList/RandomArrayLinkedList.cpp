// RandomArrayLinkedList.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
struct bilgi{
	int tsayi;
	struct bilgi * next;
};
typedef struct bilgi node;
void ListEkleTSayi(node **head, int ekleneceksayi)
{
	node *p;
	p = *head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = (node*)malloc(sizeof(node));
	p = p->next;
	p->tsayi = ekleneceksayi;
	p->next = NULL;
}
void ListGoster(node **head)
{
	node * p;
	p = *head;

	while (p != NULL)
	{
		printf("%d ", p->tsayi);
		p = p->next;
	}
	printf("Tek sayili liste");

}

void main()
{
	node * head;
	int ilkmi = 0;
	srand(time(NULL));
	int dizi[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		dizi[i] = rand() % 100;
	}
	int k;
	for (k = 0; k < 10; k++)
	{
		printf("%d ", dizi[k]);
	}
	printf("Orijinal liste\n");
	int j;
	for (j = 0; j < 10; j++)
	{
		if (dizi[j] % 2 == 1)
		{
			if (ilkmi == 0)
			{
				head = (node*)malloc(sizeof(node));
				head->tsayi = dizi[j];
				head->next = NULL;
				ilkmi = 1;
			}
			else
			{
				ListEkleTSayi(&head, dizi[j]);
			}
		}
	}
	ListGoster(&head);
	getch();
}