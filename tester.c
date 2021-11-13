#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
// Add sleep function into program - https://stackoverflow.com/questions/14818084/what-is-the-proper-include-for-the-function-sleep - 11/11/2021
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "system.h"


int main()
{
	Grid1D *gridPtr = initialize1DGrid(EMPTY_CELL);
    updateGrid1D(gridPtr, 5, FULL_CELL);
    updateGrid1D(gridPtr, 6, FULL_CELL);
    updateGrid1D(gridPtr, 7, FULL_CELL);
    updateGrid1D(gridPtr, 8, FULL_CELL);
    Cell value;
    getValueGrid1D(gridPtr, &value, 5);
    printf("%c\n", value);
    display1DGrid(gridPtr);
    updateGrid1D(gridPtr, 6, EMPTY_CELL);
    updateGrid1D(gridPtr, 7, EMPTY_CELL);
    display1DGrid(gridPtr);
	return 0;
}


