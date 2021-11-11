#define bitSize 8

typedef char Bit;

typedef struct binNumber
{
	Bit bit[bitSize];
}	BinaryNumber;

BinaryNumber* createBinaryNumber(Bit defaultBit);
void freeBinaryNumber(BinaryNumber* binNumber);