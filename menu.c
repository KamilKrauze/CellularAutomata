#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

void testGrid()
{
    Grid1D *gridPtr = initialize1DGrid(EMPTY_CELL);
    if (gridPtr == NULL)
    {
        printf("memory error \n");
    }
    updateGrid1D(gridPtr, 5, FULL_CELL);
    updateGrid1D(gridPtr, 6, FULL_CELL);
    updateGrid1D(gridPtr, 7, FULL_CELL);

    display1DGrid(gridPtr);

    Grid2D *grid2dPtr = initialize2DGrid(EMPTY_CELL);
    updateGrid2D(grid2dPtr, 1, 3, FULL_CELL);
    updateGrid2D(grid2dPtr, 9, 15, FULL_CELL);
    display2DGrid(grid2dPtr);
}

int main()
{

    testGrid();

    return 0;
}