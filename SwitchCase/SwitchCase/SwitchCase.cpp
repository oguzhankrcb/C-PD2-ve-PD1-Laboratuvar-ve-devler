// SwitchCase.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
int main() {

	/* local variable definition */
	char grade = 'B';

	switch (grade) {
	case 'A':
		printf("Excellent!\n");
		break;
	case 'B':
	case 'C':
		printf("Well done\n");
		break;
	case 'D':
		printf("You passed\n");
		break;
	case 'F':
		printf("Better try again\n");
		break;
	default:
		printf("Invalid grade\n");
		break;
	}

	printf("Your grade is  %c\n", grade);


	getch();
	return 0;
}
