#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{// b = 0x004005a0, k = 0x004009a6
	int b[5] = { 32, 23, 19, 23, 61 };
	int **k = (int**)malloc(sizeof(int));
	int *q = b;
	*k = q;
	*k += 3;
	int *p = *k;
	p -= 2;
	printf("%p %d", p, *(*k+1));

	getch();
}