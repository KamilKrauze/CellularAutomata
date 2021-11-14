#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Add sleep function into program - https://stackoverflow.com/questions/14818084/what-is-the-proper-include-for-the-function-sleep - 11/11/2021
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "system.h"
#include "grid.h"
#include "menu.h"
#include "binConv.h"

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
	printf("\t5. - Exit\n");
}

void displayMenu_BinConv()
{
	printf("========================================\n");
	printf("\t    BINARY CONVERTER\n");
	printf("========================================\n\n");
	printf("\t1. - Create binary number\n");
	printf("\t2. - Toggle show binary number\n");
	printf("\t3. - Toggle show decimal number\n");
	printf("\t4. - Convert decimal number to binary number\n");
	printf("\t5. - Save binary number to text file\n");
	printf("\t6. - Get binary number from file\n");
	printf("\t7. - Exit to main menu\n");
}

void determineChoice_BinConv()
{
	int usrChoice = 0;
	
	BinaryNumber* binNumber = createBinaryNumber('x');
	int DECnumber = 0;
	bool showBinNumber = false;
	bool showDECNumber = false;

	while (usrChoice != -1)
	{
		clear();
		displayMenu_BinConv();
		
		if(showBinNumber == true)
		{
			printf("\nBIN: ");
			displayBinaryNumber(binNumber);
		}

		if(showDECNumber == true)
		{
			printf("\nDEC: %d", DECnumber);
		}
		
		printf("\nUser: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{
		
		case 1: // Create binary number
			clear();
			
			char binString[bitSize];
			
			printf("Enter a valid 8-bit binary number below: \n\n\tExample: oxooxoox\n\nUser: ");
			scanf("%s", binString);
			
			BinStringtoBinaryNumber(binString, binNumber);
			DECnumber = convertBINtoDEC(binNumber);
			
			break;
		
		case 2: // Display binary number
			showBinNumber = !showBinNumber; // Bool flip-flop switch
			break;
		
		case 3: // Convert binary number to decimal number
			clear();
			showDECNumber = !showDECNumber;
			break;
		
		case 4: // Convert decimal number to binary number
			clear();
			printf("Enter a valid integer between 0-255: ");
			while(true)
			{
				scanf("%d", &DECnumber);
				if(DECnumber >= 0 && DECnumber <= 255)
				{
					convertDECtoBIN(binNumber, DECnumber);
					break;
				}
			}
			break;
		
		case 5: // Save binary number to text file
			clear();
			char* filepath = (char*)malloc(sizeof(char));
			if(filepath == NULL)
			{
				printf("Memory allocation error. Please try again");
			}
			printf("Please enter a file path.\nData will be appended to a file that exists\nIf the file does not exist a new one will be created with the provided name.\nExample: ../filename.txt\n");
			scanf("%s", filepath);
			saveBinaryToFile(filepath, binNumber, DECnumber);
			
			break;
		
		case 6: // Get binary number from file
			clear();

			break;
		
		case 7: // Exit bin converter
			free(binNumber);
			usrChoice = -1;
			break;
		
		default:
			clear();
			displayMenu_BinConv();
		}
	}
}

void displayMenu_1D()
{
	printf("========================================\n");
	printf("\t\t1D GRID\n");
	printf("========================================\n\n");
	printf("\t1. - Alter 1D Grid\n");
	printf("\t2. - Run Simulation\n");
	printf("\t3. - Exit to main menu\n");
}

void determineChoice_1D()
{
	int usrChoice = 0;
	Grid1D *pGrid1D = initialize1DGrid('x');

	while (usrChoice != -1)
	{
		clear();
		
		displayMenu_1D();
		display1DGrid(pGrid1D);
		
		printf("User: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{
		case 1: // Alter 1D Grid
			clear();

			int colNo=-1;
			char cellVal='@';
			while(true)
			{
				if(colNo == -1)
				{
					printf("Column Number: ");
					scanf("%d", &colNo);
				}

				if(cellVal != 'x' || cellVal != 'o')
				{	
					printf("Cell Number (x or o): ");
					scanf("%c", &cellVal);
				}

				if( colNo != -1 && (cellVal == 'x' || cellVal == 'o') )
				{
					updateGrid1D(pGrid1D, colNo, cellVal);
					break;
				}
				else
					continue;
			}
			
			break;
		case 2: // Run Simulation
			clear();
			runSimulation1d(pGrid1D, )
			break;
		case 3: // Exit Program
			usrChoice = -1;
			break;S
		default:
			clear();
			displayMenu_1D();
		}
	}
}

void determineChoice_MainMenu()
{
	int usrChoice = 0;

	while (usrChoice != -1)
	{
		clear();
		displayMenu();
		printf("User: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{
		case 1: // Binary Number Converter
			clear();
			determineChoice_BinConv();
			break;
		case 2: // 1D Grid
			clear();
			determineChoice_1D();
			break;
		case 5: // Exit Program
			_exit(0);
			break;
		default:
			clear();
			displayMenu();
		}
	}
}
