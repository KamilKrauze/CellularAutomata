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
	printf("\t7. - Exit\n");
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

			break;
		
		case 6: // Get binary number from file
			clear();

			break;
		
		case 7: // Exit Program
			_exit(0);
			break;
		
		default:
			clear();
			displayMenu_BinConv();
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
