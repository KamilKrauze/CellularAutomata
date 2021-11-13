#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "grid.h"

//
// 2D grid

Grid2D *initialize2DGrid(Cell defaultValue)
{
    printf("before");
    Grid2D *gridPtr = (Grid2D *)malloc(sizeof(Grid2D));
    printf("before");

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

bool isCellAlive(Grid2D *gridPtr, int i, int j)
{
    Cell cell;
    getValueGrid2D(gridPtr, &cell, i, j);
    return cell == FULL_CELL;
}

int calculateAdjacentCells(Grid2D *gridPtr, int i, int j, bool wrapAroundEdges)
{
    int liveAdjacentCells = 0;

    for (int loopI = -1; loopI <= 1; loopI++)
    {
        for (int loopJ = -1; loopJ <= 1; loopJ++)
        {
            int iToCheck = i + loopI;
            int jToCheck = j + loopJ;

            if (wrapAroundEdges)
            {
                if (iToCheck == -1)
                {
                    iToCheck = COL_SIZE - 1;
                }
                if (iToCheck == COL_SIZE)
                {
                    iToCheck = 0;
                }
                if (jToCheck == -1)
                {
                    jToCheck = ROW_SIZE - 1;
                }
                if (jToCheck == ROW_SIZE - 1)
                {
                    jToCheck = 0;
                }
            }
            if (isCellAlive(gridPtr, iToCheck, jToCheck))
            {
                liveAdjacentCells++;
            }
        }
    }
    return liveAdjacentCells;
}

int getNextGeneration2D(Grid2D *gridPtr, Ruleset rulesetForDeadCells, Ruleset rulesetForAliveCells, bool wrapAroundEdges)
{
    Grid2D oldGrid = *gridPtr;
    for (int i = 0; i < COL_SIZE; i++)
    {
        for (int j = 0; j < ROW_SIZE; j++)
        {
            int liveAdjacentCells = calculateAdjacentCells(&oldGrid, i, j, wrapAroundEdges);
            Cell currentCell;
            Ruleset ruleset;
            getValueGrid2D(gridPtr, &currentCell, i, j);

            if (currentCell == FULL_CELL)
            {
                ruleset = rulesetForAliveCells;
            }
            else
            {
                ruleset = rulesetForDeadCells;
            }

            if (ruleset.ruleArray[liveAdjacentCells])
            {
                updateGrid2D(gridPtr, i, j, FULL_CELL);
            }
            else
            {
                updateGrid2D(gridPtr, i, j, EMPTY_CELL);
            }
        }
    }
    return SUCCESS;
}

int runSimulation2d(Grid2D *gridPtr, Ruleset rulesetForDeadCells, Ruleset rulesetForAliveCells, bool wrapAroundEdges, int numberOfGenerations)
{
    display2DGrid(gridPtr);
    for (int i = 0; i < numberOfGenerations; i++)
    {
        getNextGeneration2D(gridPtr, rulesetForDeadCells, rulesetForAliveCells, wrapAroundEdges);
        display2DGrid(gridPtr);
    }
    printf("End of simulation");
    return SUCCESS;
}
