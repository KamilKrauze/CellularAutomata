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
bool ruleArray[] = {1, 0, 0, 0, 0, 0, 0, 0};

int main()
{
    Ruleset *rulesetPtr = (Ruleset *)malloc(sizeof(Ruleset));
    for (int i = 0; i < 8; i++)
    {
        rulesetPtr->ruleArray[i] = ruleArray[i];
    }
    Grid1D *gridPtr = initialize1DGrid(EMPTY_CELL);
    updateGrid1D(gridPtr, 5, FULL_CELL);
    updateGrid1D(gridPtr, 6, FULL_CELL);
    updateGrid1D(gridPtr, 7, FULL_CELL);
    updateGrid1D(gridPtr, 8, FULL_CELL);
    Cell value;
    getValueGrid1D(gridPtr, &value, 5);
    printf("%c\n", value);
    display1DGrid(gridPtr);

    getNextGeneration1D(gridPtr, *rulesetPtr, false);

    display1DGrid(gridPtr);
    return 0;
}
