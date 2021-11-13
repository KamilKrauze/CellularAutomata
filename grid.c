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



bool doCellsMatch(int a, Cell b)
{
    // printf("%d, %c\n", a, b);
    if (a == 0 && (b == EMPTY_CELL || b == OUT_OF_BOUNDS))
    {
        return true;
    }
    else if (a == 1 && (b == FULL_CELL)) // || b == OUT_OF_BOUNDS
    {
        return true;
    }
    // printf("Cells dont match\n");
    return false;
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
    for (int i = 0; i < ROW_SIZE; i++)
    {
        if (i == 0 && wrapAroundEdges)
        {
            getValueGrid1D(gridPtr, &prev, ROW_SIZE - 1);
        }
        else
        {
            // prev stays the same as initialized at the end of the loop
        }
        if (i == (ROW_SIZE - 1))
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
