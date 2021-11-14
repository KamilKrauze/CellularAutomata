#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
// Add sleep function into program - https://stackoverflow.     com/questions/14818084/what-is-the-proper-include-for-the-function-sleep - 11/11/2021
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "system.h"
bool ruleArray[] = {1, 0, 0, 0, 0, 0, 0, 0};

extern int grid1dColCount;
extern int grid2dColCount;
extern int grid2dRowCount;

int main()
{
    // grid2dColCount = 10;
    // grid2dRowCount = 10;

    // Grid2D *gridPtr = initialize2DGrid(EMPTY_CELL);

    // display2DGrid(gridPtr);
    // updateGrid2D(gridPtr, 5, 5, FULL_CELL);
    // updateGrid2D(gridPtr, 6, 5, FULL_CELL);
    // updateGrid2D(gridPtr, 6, 7, FULL_CELL);
    // updateGrid2D(gridPtr, 6, 6, FULL_CELL);
    // updateGrid2D(gridPtr, 5, 6, FULL_CELL);
    // display2DGrid(gridPtr);

    // runConwaysGameOfLife(gridPtr, 1, false);

    // display2DGrid(gridPtr);

    // Grid2D *gridPtr = initialize2DGrid(FULL_CELL);
    // display2DGrid(gridPtr);
    // updateGrid2D(gridPtr, 2, 2, EMPTY_CELL);
    // updateGrid2D(gridPtr, 2, 2, EMPTY_CELL);
    // updateGrid2D(gridPtr, 2, 3, EMPTY_CELL);
    // updateGrid2D(gridPtr, 2, 3, EMPTY_CELL);
    // updateGrid2D(gridPtr, 2, 3, EMPTY_CELL);
    // display2DGrid(gridPtr);
    // Cell cell;
    // getValueGrid2D(gridPtr, &cell, 0, 0);
    // printf(" Result: %c\n", cell);
    // runConwaysGameOfLife(gridPtr, 3, false);
    Ruleset* ruleset = (Ruleset *)malloc(sizeof(Ruleset));
    for (int i = 0; i < 8; i++)
    {
        ruleset->ruleArray[i]=ruleArray[i];
    }
    displayRuleset1D(*ruleset);
    

    // free2DGrid(gridPtr);
    return 0;
}
