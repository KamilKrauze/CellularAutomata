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

