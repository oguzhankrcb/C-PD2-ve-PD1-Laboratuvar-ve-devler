// LinkedListsEx1.cpp : Defines the entry point for the console application.
//
#include <stdafx.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemanbilgi{
	int no;
	char ad[30];
	struct elemanbilgi * next;
};

typedef struct elemanbilgi node;


void ListeOlustur(node ** head, int length)
{
	node *p;
	*head = (node*)malloc(sizeof(node));
	p = *head;
	int i = 0;

	for (i; i < length; i++)
	{
		if (i == 0)
		{
			printf("1. Elemanin adini ve numarasini giriniz : ");
			scanf("%s %d", p->ad, &p->no);
			p->next = NULL;
		}
		else
		{
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
			printf("%d. Elemanin adini ve numarasini giriniz : ", (i+1));
			scanf("%s %d", p->ad, &p->no);
			p->next = NULL;
		}
	}
}

void ListEkle(node ** head, int aranacakno)
{
	node * p,*q,*newp;
	p = *head;
	
	if (p->no == aranacakno)
	{
		newp = (node*)malloc(sizeof(node));
		newp->next = *head;
		printf("Yeni elemanin adini ve numarasini giriniz : ");
		scanf("%s %d", newp->ad, &newp->no);
		*head = newp;
		
	}else
	{
		while (p->next != NULL && p->no != aranacakno)
		{
			q = p;
			p = p->next;
		}

		if (p->no == aranacakno)
		{
			newp = (node*)malloc(sizeof(node));
			q->next = newp;
			newp->next = p;
			printf("Yeni elemanin adini ve numarasini giriniz : ");
			scanf("%s %d", newp->ad, &newp->no);
			return;
		}

		if (p->next == NULL)
		{
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
			printf("Yeni elemanin adini ve numarasini giriniz : ");
			scanf("%s %d", p->ad, &p->no);
			p->next = NULL;
			return;
		}

	}



}

void ListList(node** head)
{
	node * p;

	p = *head;
	int i = 0;

	while (p != NULL)
	{
		i++;
		printf("%d. elemanin adi ve numarasi : %s , %d\n", i, p->ad, p->no);
		p = p->next;
	}


}

void main()
{
	int firstmi = 0;
	node * head;
	int listeleman;
	//ListeOlustur(&head, 4);
	while (1)
	{
		system("cls");
		if (firstmi == 0)
		{
			firstmi++;
		}
		else
		{
			ListList(&head);
		}
		printf("1-Yeni Liste\n2-Yeni Giris\n3-Giris Sil\n4-Cikis\n");
		int sec;
		scanf("%d", &sec);
		switch (sec){
		case 1:
			printf("Yeni liste kac elemanli olsun : ");
			scanf("%d", &listeleman);
			ListeOlustur(&head, listeleman);
			break;
		case 2:
			printf("Yeni Eleman Hangi Numaranin Arkasina Eklensin : ");
			scanf("%d", &listeleman);
			ListEkle(&head, listeleman);
			break;
		case 4:
			exit(0);
			break;
		default:
			break;
		}
	}



	getch();

}

