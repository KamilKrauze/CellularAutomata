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

int main()
{

    Ruleset2D *rulesetPtr = (Ruleset2D *)malloc(sizeof(Ruleset2D));
    for (int i = 0; i < 9; i++)
    {
        rulesetPtr->ruleArray[i] = ruleArray[i];
        rulesetPtr->ruleArray[i] = 1;
    }

    Grid2D *gridPtr = initialize2DGrid(EMPTY_CELL);

      

    display2DGrid(gridPtr);
    updateGrid2D(gridPtr, 5, 5, FULL_CELL);
    updateGrid2D(gridPtr, 6, 5, FULL_CELL);
    updateGrid2D(gridPtr, 6, 7, FULL_CELL);
    updateGrid2D(gridPtr, 6, 6, FULL_CELL);
    updateGrid2D(gridPtr, 5, 6, FULL_CELL);
    display2DGrid(gridPtr);
    // Ruleset2D ruleset = *rulesetPtr;
    // getNextGeneration2D(gridPtr, ruleset, ruleset, true);

    runConwaysGameOfLife(gridPtr, 1, false);

    display2DGrid(gridPtr);
    free(gridPtr);
    free(rulesetPtr);

    return 0;
}
