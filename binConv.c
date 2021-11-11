#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <math.h>

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

int convertBINtoDEC(BinaryNumber* binNumber)
{
	if(binNumber == NULL)
		binNumber=createBinaryNumber('x');

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
	int i=0;
	while(decimalNumber > 0)
	{
		binNumber->binaryNo[i].bit = 'o';
		decimalNumber = decimalNumber / 2;

		i++;
	}

	return 100;
}
