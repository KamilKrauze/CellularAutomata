/**
 * Team T
 * 
 * Student Name: Vojtech Loskot
 * Matric Number: 2424633
 * 
 * Student Name: Kamil Krauze
 * Matric Number: 2414951
 * 
 * Student Name: Harry Inglis
 * Matric Number: 2411653
 */

#include <stdbool.h>
#include "grid.h"

#define SUCCESS 100
#define INVALID_INPUT_PARAMETER 101

#define PARTIAL_SUCCESS 102

#define MEMORY_ALLOCATION_ERROR 103

#define NOT_IMPLEMENTED 104
#define FILE_IO_ERROR 105

#define OUT_OF_BOUNDS 'Z'
#define EMPTY_CELL '0'
#define FULL_CELL '1'

int write1DToFile(Grid1D *gridPtr);

int write2DToFile(Grid2D *gridPtr);

Grid1D* read1DFromFile();

Grid2D* read2DFromFile();
