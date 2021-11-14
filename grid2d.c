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
    for (int rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < COL_COUNT; columnIndex++)
        {
            // gridPtr->table[i][j] = i;
            updateGrid2D(gridPtr, rowIndex, columnIndex, defaultValue);
            // printf("Initializing %d, %d, \n", i, j);
        }
    }
    (void)defaultValue;
    return gridPtr;
}

int updateGrid2D(Grid2D *gridPtr, int rowIndex, int columnIndex, Cell value)
{
    if (gridPtr == NULL || columnIndex < 0 || columnIndex > COL_COUNT || rowIndex < 0 || rowIndex > ROW_COUNT)
    {
        printf("INVALID INPUT PARAMETER");
        return INVALID_INPUT_PARAMETER;
    }
    gridPtr->table[rowIndex][columnIndex] = value;
    return SUCCESS;
}

int getValueGrid2D(Grid2D *gridPtr, Cell *target, int rowIndex, int columnIndex)
{
    if (gridPtr == NULL || columnIndex < 0 || columnIndex > COL_COUNT || rowIndex < 0 || rowIndex > ROW_COUNT)
    {
        *target = OUT_OF_BOUNDS;
        // printf("INVALID INPUT PARAMETER");

        return INVALID_INPUT_PARAMETER;
    }
    *target = gridPtr->table[rowIndex][columnIndex];
    return SUCCESS;
}

int display2DGrid(Grid2D *gridPtr)
{
    if (gridPtr == NULL)
    {
        return INVALID_INPUT_PARAMETER;
    }
    printf("\n\n");

    for (int rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < COL_COUNT; columnIndex++)
        {
            Cell value;
            getValueGrid2D(gridPtr, &value, rowIndex, columnIndex);
            printValueOfCell(value);
        }
        printf("\n");
    }
    printf("\n\n");

    return SUCCESS;
}

bool isCellAlive(Grid2D *gridPtr, int rowIndex, int columnIndex)
{
    Cell cell;
    getValueGrid2D(gridPtr, &cell, rowIndex, columnIndex);
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
                    iToCheck = ROW_COUNT - 1;
                }
                if (iToCheck == ROW_COUNT)
                {
                    iToCheck = 0;
                }
                if (jToCheck == -1)
                {
                    jToCheck = COL_COUNT - 1;
                }
                if (jToCheck == COL_COUNT - 1)
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

int getNextGeneration2D(Grid2D *gridPtr, Ruleset2D ruleset, bool wrapAroundEdges)
{
    Grid2D oldGrid = *gridPtr;
    for (int i = 0; i < ROW_COUNT; i++)
    {
        for (int j = 0; j < COL_COUNT; j++)
        {
            int liveAdjacentCells = calculateAdjacentCells(&oldGrid, i, j, wrapAroundEdges);
            Cell currentCell;
            bool *ruleArray;
            getValueGrid2D(gridPtr, &currentCell, i, j);

            if (currentCell == FULL_CELL)
            {
                ruleArray = ruleset.rulesetForAliveCells;
            }
            else
            {
                ruleArray = ruleset.rulesetForDeadCells;
            }

            if (ruleArray[liveAdjacentCells])
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

int runSimulation2d(Grid2D *gridPtr, Ruleset2D ruleset, bool wrapAroundEdges, int numberOfGenerations)
{
    display2DGrid(gridPtr);
    for (int i = 0; i < numberOfGenerations; i++)
    {
        getNextGeneration2D(gridPtr, ruleset, wrapAroundEdges);
        display2DGrid(gridPtr);
    }
    printf("End of simulation");
    return SUCCESS;
}

bool conwaysGameOfLifeRules[2][9] = {
    {0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int runConwaysGameOfLife(Grid2D *gridPtr, int numberOfGenerations, bool wrapEdges)
{
    // int *p = (int *)malloc(sizeof(int));
    // if (p == NULL)
    // {
    //     printf("Mem alloc error");
    //     return MEMORY_ALLOCATION_ERROR;
    // }
    // free(p);

    // (void)wrapEdges;
    // (void)numberOfGenerations;
    // (void)gridPtr;
    Ruleset2D *ruleset2D = (Ruleset2D *)malloc(sizeof(Ruleset2D));

    for (int i = 0; i < 8; i++)
    {
        ruleset2D->rulesetForDeadCells[i] = conwaysGameOfLifeRules[0][i];
        ruleset2D->rulesetForAliveCells[i] = conwaysGameOfLifeRules[1][i];
    }

    display2DGrid(gridPtr);
    for (int i = 0; i < numberOfGenerations; i++)
    {
        getNextGeneration2D(gridPtr, *ruleset2D, wrapEdges);
        display2DGrid(gridPtr);
    }

    printf("End of simulation");
    // (void) rulesetForDeadCells;
    free(ruleset2D);

    return SUCCESS;
}