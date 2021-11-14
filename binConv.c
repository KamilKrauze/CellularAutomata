/**
 * Student Name: Kamil Krauze
 * Matric Number: 2414951
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "binConv.h"

//Create binary number struct with a default value. 'x' or 'o'
BinaryNumber *createBinaryNumber(char defaultBit)
{
	BinaryNumber *binNumber = (BinaryNumber *)malloc(sizeof(BinaryNumber));
	if (binNumber == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < bitSize; i++)
	{
		binNumber->binaryNo[i].bit = defaultBit;
	}

	return binNumber;
}

// Display the binary number
void displayBinaryNumber(BinaryNumber *binNumber)
{
	for (int i = 0; i < bitSize; i++)
	{
		if (i == 4)
			printf(" ");
		printf("%c", binNumber->binaryNo[i].bit);
	}
	printf("\n");
}

// Free the memory allocation of the binary number.
void freeBinaryNumber(BinaryNumber *binNumber)
{
	free(binNumber);
	binNumber = NULL;
}

// Parse the string of binary numbers into the binNumber struct.
int BinStringtoBinaryNumber(char binaryString[], BinaryNumber *binNumber)
{
	if (binaryString == NULL)
		return 101; // INVALID_INPUT_PARAMETER
	if (strlen(binaryString) < bitSize)
		return 101; // INVALID_INPUT_PARAMETER
	if (binNumber == NULL)
		binNumber = createBinaryNumber('x');

	memcpy(binNumber->binaryNo, binaryString, strlen(binaryString) + 1);
	return 100; // SUCCESS
}

// Parse the binNumber struct into a string of binary numbers.
int BinaryNumbertoBinString(char *binaryString, BinaryNumber *binNumber)
{
	memcpy(binaryString, binNumber->binaryNo, sizeof(binNumber->binaryNo) + 1);
	return 100; // SUCCESS
}

// Convert the binNumber struct into a decimal number.
int convertBINtoDEC(BinaryNumber *binNumber)
{
	if (binNumber == NULL)
		binNumber = createBinaryNumber('x');

	int decimalNumber = 0;
	int row = bitSize - (bitSize - 1);
	int binValue = 1;
	for (int i = (bitSize - 1); i > 0; i--)
	{
		if (binNumber->binaryNo[i].bit == 'o') //Char comparison - https://stackoverflow.com/questions/17766754/how-to-compare-a-char/17766879 - 11/11/2021
		{
			decimalNumber += binValue;
		}
		row -= (bitSize - 1);
		binValue *= 2;
	}

	return decimalNumber;
}

// Convert the decimal number into a decimal number.
int convertDECtoBIN(BinaryNumber *binNumber, int decimalNumber)
{
	for (int i = bitSize - 1; decimalNumber > 0; i--)
	{
		if (decimalNumber % 2 == 0)
			binNumber->binaryNo[i].bit = 'x';
		else if (decimalNumber > 1)
			binNumber->binaryNo[i].bit = 'o';

		decimalNumber = decimalNumber / 2;
	}

	return 100;
}

// Append the binary number struct data and the decimal number equivalent into a file that may or may not exist.
int saveBinaryToFile(const char *filepath, BinaryNumber *binNumber, int decimalNumber)
{
	if (filepath == NULL)
	{
		return 101; // INVALID_INPUT_PARAMETER
	}

	// Opens the file in appending mode, and reading and writing - https://www.tutorialspoint.com/cprogramming/c_file_io.htm - 13/11/2021
	FILE *fp = fopen(filepath, "a+");
	if (fp != NULL)
	{
		char str[bitSize];
		BinaryNumbertoBinString(str, binNumber);
		printf("The str variable contains: %s\n", str);

		//Print the binary number into the file
		for (int i = 0; i < bitSize; ++i)
		{
			if (str[i] == 'x')
				fputc('0', fp);
			else if (str[i] == 'o')
				fputc('1', fp);
		}

		// Check if the decimal number is equal to the binary number, otherwise correct the decimal number.
		if (decimalNumber != convertBINtoDEC(binNumber))
		{
			decimalNumber = convertBINtoDEC(binNumber);
		}

		// Convert the int into a char - https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c - 13/11/2021
		char decNo[bitSize];
		sprintf(decNo, "%d", decimalNumber);

		fputs(" = ", fp);
		fputs(decNo, fp);
		fputc('\n', fp);

		fclose(fp);
	}
	return 100;
}