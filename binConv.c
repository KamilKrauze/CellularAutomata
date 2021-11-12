#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "binConv.h"

BinaryNumber* createBinaryNumber(char defaultBit)
{
	BinaryNumber* binNumber = (BinaryNumber*)malloc(sizeof(BinaryNumber));
	if (binNumber == NULL)
	{
		return NULL;
	}

	for(int i=0; i<bitSize; i++)
	{
		binNumber->binaryNo[i].bit = defaultBit;
	}

	return binNumber;
}

void displayBinaryNumber(BinaryNumber* binNumber)
{
	for (int i=0; i<bitSize; i++)
	{
		if(i == 4)
			printf(" ");
		printf("%c", binNumber->binaryNo[i].bit);
	}
	printf("\n");
}

void freeBinaryNumber(BinaryNumber* binNumber)
{
	binNumber = NULL;
	free(binNumber);
}

int BinStringtoBinaryNumber(char binaryString[], BinaryNumber* binNumber)
{
	if(binaryString == NULL)
		return 101; // INVALID_INPUT_PARAMETER
	if(strlen(binaryString) < bitSize)
		return 101; // INVALID_INPUT_PARAMETER
	if(binNumber == NULL)
		binNumber = createBinaryNumber('x');

	memcpy(binNumber->binaryNo, binaryString, strlen(binaryString)+1);
	return 100; // SUCCESS
}

int BinaryNumbertoBinString(char* binaryString, BinaryNumber* binNumber)
{
	memcpy(binaryString, binNumber->binaryNo, sizeof(binNumber->binaryNo)+1);
	return 100; // SUCCESS
}

int convertBINtoDEC(BinaryNumber* binNumber)
{
	if(binNumber == NULL)
		binNumber = createBinaryNumber('x');

	int decimalNumber=0;
	int row = bitSize - (bitSize-1);
	int binValue = 1;
	for(int i=(bitSize-1); i>0; i--)
	{
		if(binNumber->binaryNo[i].bit == 'o') //Char comparison - https://stackoverflow.com/questions/17766754/how-to-compare-a-char/17766879 - 11/11/2021
		{
			decimalNumber += binValue;
		}
		row -= (bitSize-1);
		binValue *= 2;
	}

	return decimalNumber;
}

int convertDECtoBIN(BinaryNumber* binNumber, int decimalNumber)
{
	for(int i=bitSize-1; decimalNumber>0; i--)
	{
		if(decimalNumber%2 == 0)
			binNumber->binaryNo[i].bit = 'x';
		else if (decimalNumber > 1)
			binNumber->binaryNo[i].bit = 'o';

		decimalNumber=decimalNumber/2;
	}

	return 100;
}

int saveBinaryToFile(const char* filepath, BinaryNumber* binNumber, int decimalNumber)
{	
	(void)decimalNumber;

	if(filepath == NULL)
	{
		return 101; // INVALID_INPUT_PARAMETER
	}

	printf("%p\n", filepath);

	FILE* fp = fopen(filepath, "r");
	if(fp != NULL)
	{
		char* str = (char*)malloc(sizeof(char));
		BinaryNumbertoBinString(str, binNumber);
		printf("%s\n", str);
		fputs(str, fp);

		fclose(fp);
	}


	return 100;
}
