#include <stdlib.h>
#include <stdio.h>

#include "grid.h"

char getDisplayValueOfCell(Cell value)
{
    if (value == EMPTY_CELL)
    {
        return EMPTY_CELL_SYMBOL;
    }
    else if (value == FULL_CELL)
    {
        return FULL_CELL_SYMBOL;
    }
    else
    {
        return 'X';
    }
}

void printValueOfCell(Cell value)
{
    // unsigned char emptyCH = EMPTY_CELL_SYMBOL;
    // unsigned char fullCh = FULL_CELL_SYMBOL;
    if (value == EMPTY_CELL)
    {
        printf("%c", EMPTY_CELL_SYMBOL);
    }
    else if (value == FULL_CELL)
    {
        printf("%c", FULL_CELL_SYMBOL);
    }
    else
    {
        printf("X");
    }
}

// DONE
Grid1D *initialize1DGrid(Cell defaultValue)
{
    Grid1D *gridPtr = (Grid1D *)malloc(sizeof(Grid1D));

    if (gridPtr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < ROW_SIZE; i++)
    {
        gridPtr->row[i] = defaultValue;
    }
    return gridPtr;
}

int updateGrid1D(Grid1D *gridPtr, int column, Cell value)
{
    if (gridPtr == NULL || column < 0 || column > ROW_SIZE)
    {
        return INVALID_INPUT_PARAMETER;
    }
    gridPtr->row[column] = value;
    return SUCCESS;
}

int getValueGrid1D(Grid1D *gridPtr, Cell *target, int column)
{
    if (gridPtr == NULL || column < 0 || column > ROW_SIZE)
    {
        return INVALID_INPUT_PARAMETER;
    }
    *target = gridPtr->row[column];
    return SUCCESS;
}

int display1DGrid(Grid1D *gridPtr)
{
    if (gridPtr == NULL)
    {
        return INVALID_INPUT_PARAMETER;
    }
    for (int i = 0; i < ROW_SIZE; i++)
    {
        Cell value;
        getValueGrid1D(gridPtr, &value, i);
        printValueOfCell(value);
    }
    printf("\n");
    return SUCCESS;
}

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