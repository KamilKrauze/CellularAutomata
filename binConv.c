#include <stdlib.h>

#include "binConv.h"

BinaryNumber* createBinaryNumber(Bit defaultBit)
{
	BinaryNumber* binNumber = (BinaryNumber*)malloc(sizeof(BinaryNumber));
	if (binNumber == NULL)
	{
		return NULL;
	}

	for(int i=0; i<bitSize; i++)
	{
		binNumber->bit[i] = defaultBit;
	}

	return binNumber;
}

void freeBinaryNumber(BinaryNumber* binNumber)
{
	binNumber = NULL;
	free(binNumber);
}