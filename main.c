#include <iostream>

#include "binConv.h"

int main()
{
	/**
	 * Binary conversion test.
	 */
	BinaryNumber* binNumber = createBinaryNumber('x');
	displayBinaryNumber(binNumber);
	printf("%d\n", convertBINtoDEC(binNumber));
	char str[bitSize+1] = "xoooxxox";
	BinStringtoBinaryNumber(str, binNumber);
	//convertDECtoBIN(binNumber, 32);
	displayBinaryNumber(binNumber);
	printf("%d\n", convertBINtoDEC(binNumber));
	char str2[bitSize+1] = "xx";
	BinaryNumbertoBinString(str2, binNumber);
	printf("%s\n", str2);
	freeBinaryNumber(binNumber);

	return 0;
}