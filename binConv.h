#define bitSize 8

typedef struct bit
{
	char bit;
} Bit;

typedef struct binNumber
{
	Bit binaryNo[bitSize];
}	BinaryNumber;

BinaryNumber* createBinaryNumber(Bit defaultBit);
void displayBinaryBumber(BinaryNumber* binNumber);
void freeBinaryNumber(BinaryNumber* binNumber);

int convertBINtoDEC(BinaryNumber* binNumber);