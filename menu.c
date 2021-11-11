#include <stdio.h>
#include <unistd.h> // Add sleep function into program - 

#include "system.h"

void displayMenu()
{
	printf("========================================\n");
	printf("\t\tWELCOME !\n");
	printf("========================================\n\n");
	printf("\t1. - Create 1D Grid\n");
	printf("\t2. - Create 2D Grid\n");
}

int main()
{
	displayMenu();
	sleep(0.5);
	clear();
	return 0;
}