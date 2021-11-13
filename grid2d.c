#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "grid.h"


//
// 2D grid

Grid2D *initialize2DGrid(Cell defaultValue)
{
    Grid2D *gridPtr = (Grid2D *)malloc(sizeof(Grid2D));

    if (gridPtr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COL_SIZE; j++)
        {
            gridPtr->table[i][j] = defaultValue;
        }
    }
    return gridPtr;
}

int updateGrid2D(Grid2D *gridPtr, int row, int column, Cell value)
{
    if (gridPtr == NULL || column < 0 || column > ROW_SIZE)
    {
        return INVALID_INPUT_PARAMETER;
    }
    gridPtr->table[column][row] = value;
    return SUCCESS;
}

int getValueGrid2D(Grid2D *gridPtr, Cell *target, int row, int column)
{
    if (gridPtr == NULL || column < 0 || column > ROW_SIZE)
    {
        return INVALID_INPUT_PARAMETER;
    }
    *target = gridPtr->table[column][row];
    return SUCCESS;
}

int display2DGrid(Grid2D *gridPtr)
{
    if (gridPtr == NULL)
    {
        return INVALID_INPUT_PARAMETER;
    }
    printf("\n\n");

    for (int i = 0; i < COL_SIZE; i++)
    {
        for (int j = 0; j < ROW_SIZE; j++)
        {
            Cell value;
            getValueGrid2D(gridPtr, &value, i, j);
            printValueOfCell(value);
        }
        printf("\n");
    }
    printf("\n\n");

    return SUCCESS;
}
