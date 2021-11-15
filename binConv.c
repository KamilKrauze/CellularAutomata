/**
 * Student Name: Kamil Krauze
 * Matric Number: 2414951
 * 
 */

/**
 * Student Name: Vojtech Loskot
 * Matric Number: 2424633
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "binConv.h"
#include "grid.h"
#include "itoa.h"

//Create binary number struct with a default value. '1' or '0'
BinaryNumber *createBinaryNumber(char defaultBit, int numberOfBits)
{
	BinaryNumber *binNumber = (BinaryNumber *)malloc(sizeof(BinaryNumber) + (numberOfBits * sizeof(Bit)));
	if (binNumber == NULL)
	{
		return NULL;
	}
	binNumber->numberOfBits = numberOfBits;

	for (int i = 0; i < numberOfBits; i++)
	{
		binNumber->binaryNo[i].bit = defaultBit;
	}

	return binNumber;
}

// Display the binary number
void displayBinaryNumber(BinaryNumber *binNumber)
{
	for (int i = 0; i < binNumber->numberOfBits; i++)
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
	if (binNumber == NULL)
	{
		printf("INVALID_INPUT_PARAMETER");
		return INVALID_INPUT_PARAMETER;
	}
	memcpy(binNumber->binaryNo, binaryString, strlen(binaryString) + 1);
	return 100; // SUCCESS
}

// Parse the binNumber struct into a string of binary numbers.
int BinaryNumbertoBinString(char *binaryString, BinaryNumber *binNumber)
{
	memcpy(binaryString, binNumber->binaryNo, sizeof(binNumber) + (binNumber->numberOfBits * sizeof(Bit)) + 1);
	return 100; // SUCCESS
}

// Convert the binNumber struct into a decimal number.
int convertBINtoDEC(BinaryNumber *binNumber)
{
	if (binNumber == NULL)
	{
		printf("INVALID_INPUT_PARAMETER");
		return INVALID_INPUT_PARAMETER;
	}
	// binNumber = createBinaryNumber('0');

	int decimalNumber = 0;
	int binValue = 128;
	for (int i = 0; i < binNumber->numberOfBits; i++)
	{
		if (binNumber->binaryNo[i].bit == '1') //Char comparison - https://stackoverflow.com/questions/17766754/how-to-compare-a-char/17766879 - 11/11/2021
		{
			decimalNumber += binValue;
			printf("NO: %d\n", decimalNumber);
		}
		binValue = binValue / 2;
	}

	return decimalNumber;
}

// Convert the decimal number into a binary number.
int convertDECtoBIN(BinaryNumber *binNumber, int decimalNumber)
{
	for (int i = binNumber->numberOfBits - 1; decimalNumber > 0; i--)
	{
		if (decimalNumber % 2 == 0)
			binNumber->binaryNo[i].bit = '0';
		else if (decimalNumber % 2 >= 1)
			binNumber->binaryNo[i].bit = '1';

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
		char *str = (char *)malloc(sizeof(char) * (binNumber->numberOfBits));
		BinaryNumbertoBinString(str, binNumber);
		printf("The str variable contains: %s\n", str);

		//Print the binary number into the file
		for (int i = 0; i < binNumber->numberOfBits; ++i)
		{
			if (str[i] == '0')
				fputc('0', fp);
			else if (str[i] == '1')
				fputc('1', fp);
		}

		// Check if the decimal number is equal to the binary number, otherwise correct the decimal number.
		if (decimalNumber != convertBINtoDEC(binNumber))
		{
			decimalNumber = convertBINtoDEC(binNumber);
		}

		// Convert the int into a char - https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c - 13/11/2021
		char decNo[50];
		sprintf(decNo, "%d", decimalNumber);

		fputs(" = ", fp);
		fputs(decNo, fp);
		fputc('\n', fp);

		fclose(fp);
		free(str);
	}
	return 100;
}

int parseBinaryInput(int numberOfBits, BinaryNumber *output)
{
	int numberInput;
	printf("\tBinary number (either in decimal or binary)\n");
	scanf("%d", &numberInput);
	printf("\n");

	if (numberInput > (2 ^ numberOfBits))
	{
		//parse as binary
		char *stringInput = (char *)malloc(sizeof(char) * (numberOfBits));

		itoa(numberInput, stringInput, 10);
		BinStringtoBinaryNumber(stringInput, output);
	}
	else
	{
		//parse as decimal
		convertDECtoBIN(output, numberInput);
	}
	return SUCCESS;
}

