#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
        *target = OUT_OF_BOUNDS;
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

int myRuleset[8][3] = {
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1},
    {1, 0, 0},
    {0, 1, 1},
    {0, 1, 0},
    {0, 0, 1},
    {0, 0, 0},
};

bool doCellsMatch(int a, Cell b)
{
    if (a == 0 && (b == EMPTY_CELL || b == OUT_OF_BOUNDS))
    {
        return true;
    }
    else if (a == 1 && (b == FULL_CELL || b == OUT_OF_BOUNDS))
    {
        return true;
    }
    return false;
}

int getNextGeneration1D(Grid1D *gridPtr, Ruleset ruleset, bool wrapAroundEdges)
{
    (void) ruleset;
    Grid1D oldGrid = *gridPtr;
    for (int i = 0; i < ROW_SIZE; i++)
    {
        Cell prev;
        Cell me;
        Cell next;
        if (i == 0 && wrapAroundEdges)
        {
            getValueGrid1D(&oldGrid, &prev, ROW_SIZE - 1);
        }
        else
        {
            getValueGrid1D(&oldGrid, &prev, i - 1);
        }
        if (i == (ROW_SIZE - 1) && wrapAroundEdges)
        {
            getValueGrid1D(&oldGrid, &next, 0);
        }
        else
        {
            getValueGrid1D(&oldGrid, &prev, i + 1);
        }
        getValueGrid1D(&oldGrid, &me, i);

        for (int j = 0; j < 8; j++)
        {
            if (doCellsMatch(myRuleset[j][0], prev) && doCellsMatch(myRuleset[j][1], me) && doCellsMatch(myRuleset[j][2], next))
            {
                gridPtr->row[i] = FULL_CELL;
            }
            else
            {
                gridPtr->row[i] = EMPTY_CELL;
            }
        }
    }
    return SUCCESS;
}
