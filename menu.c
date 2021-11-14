#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
// Add sleep function into program - https://stackoverflow.com/questions/14818084/what-is-the-proper-include-for-the-function-sleep - 11/11/2021
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "system.h"

extern int grid1dColCount;
extern int grid2dColCount;
extern int grid2dRowCount;


void displayMenu()
{
	printf("========================================\n");
	printf("\t\tWELCOME !\n");
	printf("========================================\n\n");
	printf("\t1. - Binary Converter\n");
	printf("\t2. - 1D Grid\n");
	printf("\t3. - 2D Grid\n");
	printf("\t4. - Run tester\n");
	printf("\t5. - Exit\n");
}

void determineChoice_MainMenu()
{

	displayMenu();
	int usrChoice = 0;

	while (usrChoice != -1)
	{
		printf("User: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{
		case 1:
			clear();
			determineChoice_3DGrid();
			
			break;
		case 2:
			clear();
			determineChoice_2DGrid();
			break;
		case 3:
			clear();
			determineChoice_1DGrid();
			break;
		case 4:
			clear();
			// RUN TEST FUNCTION
			break;
		case 5:
			_exit(0);
			break;
		default:
			clear();
			displayMenu();
		}
	}
}
