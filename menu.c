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

void displayMenu()
{
	printf("========================================\n");
	printf("\t\tWELCOME !\n");
	printf("========================================\n\n");
	printf("\t1. - Create 1D Grid\n");
	printf("\t2. - Create 2D Grid\n");
	printf("\t3. - Create 3D Grid\n");
	printf("\t4. - Run tester\n");

	printf("\t5. - Exit\n");
}

void create1D_subMenu()
{
	printf("\n\n========================================\n");
	printf("\t\t1D GRID !\n");
	printf("========================================\n\n");
	printf("\t1. - Read from file\n");
	printf("\t2. - Write to file\n");
	printf("\t3. - Initialize grid\n");
	printf("\t4. - Back to Main Menu\n");
	printf("\t5. - Exit\n");
}

void create2D_subMenu()
{
	printf("\n\n========================================\n");
	printf("\t\t2D GRID !\n");
	printf("========================================\n\n");
	printf("\t1. - Read from file\n");
	printf("\t2. - Write to file\n");
	printf("\t3. - Initialize grid\n");
	printf("\t4. - Back to Main Menu\n");
	printf("\t5. - Exit\n");
}

void create3D_subMenu()
{
	printf("\n\n========================================\n");
	printf("\t\t2D GRID !\n");
	printf("========================================\n\n");
	printf("\t1. - Read from file\n");
	printf("\t2. - Write to file\n");
	printf("\t3. - Initialize grid\n");
	printf("\t4. - Back to Main Menu\n");
	printf("\t5. - Exit\n");
}

void determineChoice_1DGrid()
{

	create1D_subMenu();
	int usrChoice = 0;

	while (usrChoice != -1)
	{
		printf("User: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{
		case 1:
			clear();
			// Read file
			break;
		case 2:
			clear();
			// Write to file
			break;
		case 3:
			clear();
			// Initialize grid
			break;
		case 4:
			clear();
			displayMenu();
			break;
		case 5:
			_exit(0);
			break;
		default:
			clear();
			create1D_subMenu();
		}
	}
}

void determineChoice_2DGrid()
{

	create2D_subMenu();
	int usrChoice = 0;

	while (usrChoice != -1)
	{
		printf("User: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{
		case 1:
			clear();
			// Read file
			break;
		case 2:
			clear();
			// Write to file
			break;
		case 3:
			clear();
			// Initialize grid
			break;
		case 4:
			clear();
			displayMenu();
			break;
		case 5:
			_exit(0);
			break;
		default:
			clear();
			create2D_subMenu();
		}
	}
}
void determineChoice_3DGrid()
{

	create3D_subMenu();
	int usrChoice = 0;

	while (usrChoice != -1)
	{
		printf("User: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{
		case 1:
			clear();
			// Read file
			break;
		case 2:
			clear();
			// Write to file
			break;
		case 3:
			clear();
			// Initialize grid
			break;
		case 4:
			clear();
			displayMenu();
			break;
		case 5:
			_exit(0);
			break;
		default:
			clear();
			create3D_subMenu();
		}
	}
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
			determineChoice_1DGrid();
			break;
		case 2:
			clear();
			determineChoice_2DGrid();
			break;
		case 3:
			clear();
			determineChoice_3DGrid();
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

int main()
{
	determineChoice_MainMenu();
	return 0;
}
