/**
 * Student Name: Vojtech Loskot
 * Matric Number: 2424633
 * 
 * Student Name: Kamil Krauze
 * Matric Number: 2414951
 * 
 */
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
#include "menu.h"
#include "binConv.h"
#include "IO.h"

void displayMenu()
{
	printf("========================================\n");
	printf("\t\tWELCOME !\n");
	printf("========================================\n\n");
	printf("\t1. - Binary Converter\n");
	printf("\t2. - 1D Grid\n");
	printf("\t3. - 2D Grid\n");
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

	BinaryNumber *binNumber = createBinaryNumber('0', 8);
	int DECnumber = 0;
	bool showBinNumber = false;
	bool showDECNumber = false;

	while (usrChoice != -1)
	{
		clear();
		displayMenu_BinConv();

		if (showBinNumber == true)
		{
			printf("\nBIN: ");
			displayBinaryNumber(binNumber);
		}

		if (showDECNumber == true)
		{
			printf("\nDEC: %d", DECnumber);
		}

		printf("\nUser: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{

		case 1: // Create binary number
			clear();

			char *binString = (char *)malloc(sizeof(char) * (binNumber->numberOfBits));

			printf("Enter a valid 8-bit binary number below: \n\n\tExample: oxooxoox\n\nUser: ");
			scanf("%s", binString);

			BinStringtoBinaryNumber(binString, binNumber);
			DECnumber = convertBINtoDEC(binNumber);
			free(binString);
			break;

		case 2:								// Display binary number
			showBinNumber = !showBinNumber; // Bool flip-flop switch
			break;

		case 3: // Convert binary number to decimal number
			clear();
			showDECNumber = !showDECNumber;
			break;

		case 4: // Convert decimal number to binary number
			clear();
			printf("Enter a valid integer between 0-255: ");
			while (true)
			{
				scanf("%d", &DECnumber);
				if (DECnumber >= 0 && DECnumber <= 255)
				{
					convertDECtoBIN(binNumber, DECnumber);
					break;
				}
			}
			break;

		case 5: // Save binary number to text file
			clear();
			char *filepath = (char *)malloc(sizeof(char));
			if (filepath == NULL)
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
	printf("\t1. - Change 1D Grid size. Current number of fields: %d\n", grid1dColCount);
	printf("\t2. - Change ruleset\n");
	printf("\t3. - Run Simulation\n");
	printf("\t4. - Read grid from save file\n");
	printf("\t5. - Write grid to save file\n");
	printf("\t6. - Exit to main menu\n");
}

Ruleset *pGlobalRulset1D = NULL;

void determineChoice_1D()
{
	int usrChoice = 0;
	bool option1Valid = false;
	bool option2Valid = false;
	bool option3Valid = false;

	Grid1D *pGrid1D = initialize1DGrid(EMPTY_CELL);
	BinaryNumber *binNumber = createBinaryNumber('x', 8);

	if (pGlobalRulset1D == NULL)
		pGlobalRulset1D = initialize1DRuleset();

	while (usrChoice != -1)
	{
		clear();

		displayMenu_1D();
		display1DGrid(pGrid1D);
		displayRuleset1D(*pGlobalRulset1D);

		printf("User: ");
		scanf("%d", &usrChoice);

		switch (usrChoice)
		{
		case 1: // Alter 1D Grid
			clear();

			int colNo = -1;
			int cellVal = -1;
			bool assigned = false;
			while (assigned != true)
			{
				if (colNo == -1)
				{
					printf("Column Number: ");
					scanf("%d", &colNo);
				}

				if (cellVal != 1 || cellVal != 0)
				{
					printf("Cell Number (0 for dead, 1 for alive): ");
					scanf("%d", &cellVal);
				}

				if (colNo != -1 && (cellVal == 1 || cellVal == 0))
				{
					if (cellVal == 1)
					{
						updateGrid1D(pGrid1D, colNo, FULL_CELL);
						assigned = true;
					}
					else
					{
						updateGrid1D(pGrid1D, colNo, EMPTY_CELL);
						assigned = true;
					}
				}
				else
					continue;
			}

			break;
		case 2: // Alter rule set

			parseBinaryInput(8, binNumber);
			char str[8];
			BinaryNumbertoBinString(str, binNumber);
			for (int i = 0; i < 8; ++i)
			{
				if (str[i] == '0')
					pGlobalRulset1D->ruleArray[i] = 0;
				else if (str[i] == '1')
					pGlobalRulset1D->ruleArray[i] = 1;
			}

			break;
		case 3: // Run Simulation
			clear();
			int userIn = -1;
			bool wrapEdges = false;
			int genNumber = 0;
			float time = 0;

			while (option1Valid != true)
			{
				printf("Please enter the number of generations you would like to simulate: ");
				scanf("%d", &genNumber);

				if (genNumber > 0)
					option1Valid = true;
			}

			while (option2Valid != true)
			{
				printf("Would like for it to wrap around the edges? \n(1 for yes, 0 for no)\n");
				printf("User: ");
				scanf("%d", &userIn);

				switch (userIn)
				{
				case 1:
					wrapEdges = true;
					option2Valid = true;
					break;
				case 0:
					wrapEdges = false;
					option2Valid = true;
					break;
				default:
					clear();
					break;
				}
			}

			while (option3Valid != true)
			{
				printf("How long would you like to run the simulation for?\nProvide the time in seconds (0.01 for millieseconds), 0 to skip step-by-step results till end of simulation\n");
				printf("User: ");
				scanf("%f", &time);

				if (time >= 0)
				{
					option3Valid = true;
				}
			}

			option1Valid = option2Valid = option3Valid = false;

			runSimulation1d(pGrid1D, *pGlobalRulset1D, wrapEdges, genNumber, time);

			break;
		case 4: //Read  1D grid from file
			pGrid1D = read1DFromFile();
			break;
		case 5: //Write 1D grid from file
			write1DToFile(pGrid1D);
			break;
		case 6: // Exit Program
			usrChoice = -1;
			determineChoice_MainMenu();
			break;
		default:
			clear();
			displayMenu_1D();
		}
	}
	free(pGrid1D);
}

void displayMenu_2D()
{
	printf("========================================\n");
	printf("\t\t2D GRID\n");
	printf("========================================\n\n");
	printf("\t1. - Change 2D Grid size. Current number of rows is %d and columns %d\n", grid2dRowCount, grid2dColCount);
	printf("\t2. - Change ruleset\n");
	printf("\t3. - Run Simulation\n");
	printf("\t4. - Read grid from save file\n");
	printf("\t5. - Write grid to save file\n");
	printf("\t4. - Exit to main menu\n");
}

Ruleset2D *globalRuleset2dPtr = NULL;

void determineChoice_2D()
{
	int usrChoice = 0;
	Grid2D *gridPtr = initialize2DGrid(EMPTY_CELL);
	if (globalRuleset2dPtr == NULL)
	{
		globalRuleset2dPtr = initialize2DRuleset();
	}

	while (usrChoice != -1)
	{
		clear();

		displayMenu_2D();
		display2DGrid(gridPtr);

		printf("User: ");
		scanf("%d", &usrChoice);
		switch (usrChoice)
		{
		case 1:
			clear();
			printf("========================================\n");
			printf("\t\tChanging 2D grid size\n");
			printf("========================================\n\n");
			printf("\t\tCurrent number of rows is %d \n", grid2dRowCount);
			printf("\t\tNew number of rows in a 2D grid: ");
			scanf("%d", &grid2dRowCount);
			printf("\n");
			printf("\t\tCurrent number of columns is %d \n", grid2dColCount);
			printf("\t\tNew number of columns in a 2D grid: ");
			scanf("%d", &grid2dColCount);
			printf("\n");
			free2DGrid(gridPtr);
			gridPtr = initialize2DGrid(EMPTY_CELL);

			break;
		case 2:
			clear();
			printf("========================================\n");
			printf("\t\tChanging Ruleset\n");
			printf("========================================\n\n");
			printf("\tThe ruleset for the 2D Cell automata consists of two 9-bit numbers,\n");
			printf("\tone indicating the behavior for live cells and the other for dead cells.\n");
			printf("\tYou will be prompted to enter these numbers separately.\n");
			printf("\n");

			printf("\tIf you think of the binary number as an array of bits then\n");
			printf("\tthe index is the number of alive adjacent cells (0-8) and the value is the state of the cell.\n");
			printf("\n");

			printf("\tFor example: The number 1000 0000 0 would result in a cell with 0 adjacent live cells to survive and all others to die out\n");
			printf("\n");
			printf("\n");

			printf("\t\tCurrent Ruleset:\n");

			displayRuleset2D(*globalRuleset2dPtr);
			printf("\n");
			printf("\t\tNew Ruleset for living cells (1 - stay alive, 0 - die out):\n");
			BinaryNumber *inputAlive = createBinaryNumber('0', 9);
			parseBinaryInput(9, inputAlive);

			printf("\n");
			printf("\t\tNew Ruleset for dead cells (1 - come alive, 0 - stay dead):\n");
			BinaryNumber *inputDead = createBinaryNumber('0', 9);
			parseBinaryInput(9, inputDead);

			for (int i = 0; i < 9; i++)
			{
				printf("Input numbers %c %c", inputAlive->binaryNo[i].bit, inputDead->binaryNo[i].bit);
				if (inputAlive->binaryNo[i].bit == '1')
				{
					globalRuleset2dPtr->rulesetForAliveCells[i] = true;
				}
				else
				{
					globalRuleset2dPtr->rulesetForAliveCells[i] = false;
				}

				if (inputDead->binaryNo[i].bit == '1')
				{
					globalRuleset2dPtr->rulesetForDeadCells[i] = true;
				}
				else
				{
					globalRuleset2dPtr->rulesetForDeadCells[i] = false;
				}
			}

			scanf("%d", &usrChoice);
			free(inputDead);
			free(inputAlive);

			// int number1;
			// scanf("%d", &number1);

			break;
		case 3: // Run Simulation
			clear();
			printf("========================================\n");
			printf("\t\tRun simulation\n");
			printf("========================================\n\n");
			printf("\tThis is the current ruleset:\n\n");
			displayRuleset2D(*globalRuleset2dPtr);
			printf("\n");

			printf("\tThis is the current state of the display:\n\n");
			display2DGrid(gridPtr);
			printf("\n");

			printf("\tHow many generations do you want to run?");
			printf("\n");
			int numberOfGenerations;
			scanf("%d", &numberOfGenerations);
			printf("\tDo you wanna wrap the board around the edges - 3D Donut style? (1 or 0)");
			printf("\n");
			bool wrapAroundEdges;
			int wrapAroundEdgesInt;

			scanf("%d", &wrapAroundEdgesInt);
			wrapAroundEdges = wrapAroundEdgesInt;
			// runSimulation1d(pGrid1D, ruleset1D, false, 10);
			runSimulation2d(gridPtr, *globalRuleset2dPtr, wrapAroundEdges, numberOfGenerations);

			printf("Simulation done, type anything to continue.\n");
			int useless;
			scanf("%d", &useless);
			break;
		case 4: //Read  1D grid from file
			free2DGrid(gridPtr);
			gridPtr = read2DFromFile();
			break;
		case 5: //Write 1D grid to file
			clear();
			write2DToFile(gridPtr);
			printf("Saved to file saved2D.txt\n");
			// sleep(100);
			break;
		case 6: // Exit Program
			usrChoice = -1;
			free2DGrid(gridPtr);
			free(globalRuleset2dPtr);
			break;
			break;
		default:
			clear();
			// displayMenu_1D();
			break;
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
		case 3: // 1D Grid
			clear();
			determineChoice_2D();
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
