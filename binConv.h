#define bitSize 8

typedef struct bit
{
	char bit;
} Bit;

typedef struct binNumber
{
	Bit binaryNo[bitSize];
}	BinaryNumber;

BinaryNumber* createBinaryNumber(char defaultBit);
void displayBinaryNumber(BinaryNumber* binNumber);
void freeBinaryNumber(BinaryNumber* binNumber);

int convertBINtoDEC(BinaryNumber* binNumber);