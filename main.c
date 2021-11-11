#include <iostream>

#include "binConv.h"

int main()
{
	BinaryNumber* binNumber = createBinaryNumber('x');
	displayBinaryNumber(binNumber);
	printf("%d\n", convertBINtoDEC(binNumber));
	freeBinaryNumber(binNumber);

	return 0;
}