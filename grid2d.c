#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <cstring>

#include "grid.h"

//
// 2D grid

int grid2dRowCount = 8;
int grid2dColCount = 15;

// https://stackoverflow.com/questions/54795235/flexible-array-of-flexible-arrays-in-c
Grid2D *initialize2DGrid(Cell defaultValue)
{
    Grid2D *gridPtr = (Grid2D *)malloc(sizeof(Grid2D) + grid2dRowCount * sizeof(Cell *));

    if (gridPtr == NULL)
    {
        return NULL;
    }
    for (int rowIndex = 0; rowIndex < grid2dRowCount; rowIndex++)
    {
        Cell *arr = (Cell *)malloc(grid2dColCount * sizeof(Cell));
        if (arr == NULL)
        {
            printf("MEMORY ERROR");
            return NULL;
        }
        gridPtr->table[rowIndex] = arr;
        for (int columnIndex = 0; columnIndex < grid2dColCount; columnIndex++)
        {
            // gridPtr->table[i][j] = i;
            updateGrid2D(gridPtr, rowIndex, columnIndex, defaultValue);
            // printf("Initializing %d, %d, \n", rowIndex, columnIndex);
        }
    }
    // (void)defaultValue;
    Cell cell;
    getValueGrid2D(gridPtr, &cell, 0, 0);
    printf("Test %c, \n", cell);

    return gridPtr;
}

void free2DGrid(Grid2D *gridPtr)
{
    for (int rowIndex = 0; rowIndex < grid2dRowCount; rowIndex++)
    {
        free(gridPtr->table[rowIndex]);
    }
    free(gridPtr);
}

int updateGrid2D(Grid2D *gridPtr, int rowIndex, int columnIndex, Cell value)
{
    if (gridPtr == NULL || columnIndex < 0 || columnIndex >= grid2dColCount || rowIndex < 0 || rowIndex >= grid2dRowCount)
    {
        printf("INVALID INPUT PARAMETER");
        return INVALID_INPUT_PARAMETER;
    }
    gridPtr->table[rowIndex][columnIndex] = value;
    return SUCCESS;
}

int getValueGrid2D(Grid2D *gridPtr, Cell *target, int rowIndex, int columnIndex)
{
    if (gridPtr == NULL || columnIndex < 0 || columnIndex >= grid2dColCount || rowIndex < 0 || rowIndex >= grid2dRowCount)
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

    for (int rowIndex = 0; rowIndex < grid2dRowCount; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < grid2dColCount; columnIndex++)
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

Cell temporaryCell;
bool isCellAlive(Grid2D *gridPtr, int rowIndex, int columnIndex)
{
    // printf("Checking cell at row: %d and column: %d \n", rowIndex, columnIndex);
    // printf("Getting cell at row: %d and column: %d ", rowIndex, columnIndex);

    getValueGrid2D(gridPtr, &temporaryCell, rowIndex, columnIndex);
    // printf(" Result: %c\n", temporaryCell);
    return temporaryCell == FULL_CELL;
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
                    iToCheck = grid2dRowCount - 1;
                }
                if (iToCheck == grid2dRowCount)
                {
                    iToCheck = 0;
                }
                if (jToCheck == -1)
                {
                    jToCheck = grid2dColCount - 1;
                }
                if (jToCheck == grid2dColCount - 1)
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
    // printf("Live cells %d\n", liveAdjacentCells);

    return liveAdjacentCells;
}

Grid2D *getGrid2DCopy(Grid2D *gridPtr)
{
    Grid2D *oldGridCopyPtr = initialize2DGrid(EMPTY_CELL);

    for (int rowIndex = 0; rowIndex < grid2dRowCount; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < grid2dColCount; columnIndex++)
        {
            Cell cell;
            getValueGrid2D(gridPtr, &cell, rowIndex, columnIndex);
            updateGrid2D(oldGridCopyPtr, rowIndex, columnIndex, cell);
        }
    }
    return oldGridCopyPtr;
}

int getNextGeneration2D(Grid2D *gridPtr, Ruleset2D ruleset, bool wrapAroundEdges)
{

    Grid2D *oldGridCopyPtr = getGrid2DCopy(gridPtr);

    // printf("Displaying grids before conways GoL");

    // display2DGrid(gridPtr);
    // display2DGrid(oldGridCopyPtr);

    for (int i = 0; i < grid2dRowCount; i++)
    {
        for (int j = 0; j < grid2dColCount; j++)
        {

            int liveAdjacentCells = calculateAdjacentCells(oldGridCopyPtr, i, j, wrapAroundEdges);
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
    free2DGrid(oldGridCopyPtr);
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
    Ruleset2D *ruleset2D = (Ruleset2D *)malloc(sizeof(Ruleset2D));

    for (int i = 0; i < 8; i++)
    {
        ruleset2D->rulesetForDeadCells[i] = conwaysGameOfLifeRules[0][i];
        ruleset2D->rulesetForAliveCells[i] = conwaysGameOfLifeRules[1][i];
    }

    printf("Starting Conways game of life\n");

    display2DGrid(gridPtr);
    for (int i = 0; i < numberOfGenerations; i++)
    {
        // printf("Generation %d\n", i);
        getNextGeneration2D(gridPtr, *ruleset2D, wrapEdges);
        display2DGrid(gridPtr);
    }

    printf("End of simulation\n");
    // (void) rulesetForDeadCells;
    free(ruleset2D);

    return SUCCESS;
}