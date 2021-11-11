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

int BinStringtoBinaryNumber(char* binaryString, BinaryNumber* binNumber);
int BinaryNumbertoBinString(char* binaryString, BinaryNumber* binNumber);
int convertBINtoDEC(BinaryNumber* binNumber);
int convertDECtoBIN(BinaryNumber* binNumber, int decimalNumber);

