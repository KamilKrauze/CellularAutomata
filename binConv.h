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
// #define bitSize 8

typedef struct bit
{
	char bit;
} Bit;

typedef struct binNumber
{
	int numberOfBits;
	Bit binaryNo[];
}	BinaryNumber;

BinaryNumber* createBinaryNumber(char defaultBit, int numberOfBits);
void displayBinaryNumber(BinaryNumber* binNumber);
void freeBinaryNumber(BinaryNumber* binNumber);

int BinStringtoBinaryNumber(char* binaryString, BinaryNumber* binNumber);
int BinaryNumbertoBinString(char* binaryString, BinaryNumber* binNumber);
int convertBINtoDEC(BinaryNumber* binNumber);
int convertDECtoBIN(BinaryNumber* binNumber, int decimalNumber);

int saveBinaryToFile(const char* filepath, BinaryNumber* binNumber, int decimalNumber);

int parseBinaryInput(int numberOfBits, BinaryNumber *output);
// int binaryNumberToRuleset