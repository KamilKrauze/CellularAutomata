/**
 * Student Name: Vojtech Loskot
 * Matric Number: 2424633
 * 
 * Student Name: Kamil Krauze
 * Matric Number: 2414951
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Add sleep function into program - https://stackoverflow.com/questions/14818084/what-is-the-proper-include-for-the-function-sleep - 11/11/2021
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "system.h"
#include "grid.h"



// DONE
int grid1dColCount = 15;
Grid1D *initialize1DGrid(Cell defaultValue)
{
    Grid1D *gridPtr = (Grid1D *)malloc(sizeof(Grid1D) + (grid1dColCount * sizeof(Cell)));

    if (gridPtr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < grid1dColCount; i++)
    {
        gridPtr->row[i] = defaultValue;
    }
    return gridPtr;
}

int updateGrid1D(Grid1D *gridPtr, int column, Cell value)
{
    if (gridPtr == NULL || column < 0 || column >= grid1dColCount)
    {
        return INVALID_INPUT_PARAMETER;
    }
    gridPtr->row[column] = value;
    return SUCCESS;
}

int getValueGrid1D(Grid1D *gridPtr, Cell *target, int column)
{
    if (gridPtr == NULL || column < 0 || column >= grid1dColCount)
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
    for (int i = 0; i < grid1dColCount; i++)
    {
        Cell value;
        getValueGrid1D(gridPtr, &value, i);
        printValueOfCell(value);
    }
    printf("\n");
    return SUCCESS;
}

static int rulesetTemplate[8][3] = {
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1},
    {1, 0, 0},
    {0, 1, 1},
    {0, 1, 0},
    {0, 0, 1},
    {0, 0, 0},
};

Ruleset *initialize1DRuleset()
{

    Ruleset* ruleset1D = (Ruleset*)malloc(sizeof(Ruleset));
    if (ruleset1D == NULL)
    {
        printf("MEMORY ALLOCATION ERROR");
        return NULL;
    }
    
    // Default rule set
    ruleset1D->ruleArray[0] = 0;
    ruleset1D->ruleArray[1] = 0;
    ruleset1D->ruleArray[2] = 0;
    ruleset1D->ruleArray[3] = 1;
    ruleset1D->ruleArray[4] = 1;
    ruleset1D->ruleArray[5] = 1;
    ruleset1D->ruleArray[6] = 1;
    ruleset1D->ruleArray[7] = 0;

    return ruleset1D;
}

int getNextGeneration1D(Grid1D *gridPtr, Ruleset ruleset, bool wrapAroundEdges)
{
    (void)ruleset;
    Cell zeroIndexValueOfOldGrid;
    getValueGrid1D(gridPtr, &zeroIndexValueOfOldGrid, 0);

    Cell prev;
    Cell me;
    Cell next;
    getValueGrid1D(gridPtr, &prev, -1);
    for (int i = 0; i < grid1dColCount; i++)
    {
        if (i == 0 && wrapAroundEdges)
        {
            getValueGrid1D(gridPtr, &prev, grid1dColCount - 1);
        }
        else
        {
            // prev stays the same as initialized at the end of the loop
        }
        if (i == (grid1dColCount - 1))
        {
            if (wrapAroundEdges)
            {

                next = zeroIndexValueOfOldGrid;
            }
            else
            {
                next = OUT_OF_BOUNDS;
            }
        }
        else
        {
            getValueGrid1D(gridPtr, &next, i + 1);
        }
        getValueGrid1D(gridPtr, &me, i);

        for (int j = 0; j < 8; j++)
        {
            // printf("Cells at index %d, prev: %c me: %c next: %c \n ", i, prev, me, next);
            if (doCellsMatch(rulesetTemplate[j][0], prev) && doCellsMatch(rulesetTemplate[j][1], me) && doCellsMatch(rulesetTemplate[j][2], next))
            {
                if (ruleset.ruleArray[j])
                {
                    // printf("Filling in a cell");
                    gridPtr->row[i] = FULL_CELL;
                }
                else
                {
                    // printf("Removing  a cell");
                    gridPtr->row[i] = EMPTY_CELL;
                }
            }
        }
        prev = me;
    }
    return SUCCESS;
}

int runSimulation1d(Grid1D *gridPtr, Ruleset ruleset, bool wrapAroundEdges, int numberOfGenerations, float time)
{
    display1DGrid(gridPtr);
    for (int i = 0; i < numberOfGenerations; i++)
    {
        clear();
        getNextGeneration1D(gridPtr, ruleset, wrapAroundEdges);
        display1DGrid(gridPtr);
        sleep(time);
    }
    printf("End of simulation\n");
    return SUCCESS;
}
    