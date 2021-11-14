#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "grid.h"

// Since we're dealing with strings this turned out to be terribly impractical
// char getDisplayValueOfCell(Cell value)
// {
//     if (value == EMPTY_CELL)
//     {
//         return EMPTY_CELL_SYMBOL;
//     }
//     else if (value == FULL_CELL)
//     {
//         return FULL_CELL_SYMBOL;
//     }
//     else
//     {
//         return 'X';
//     }
// }

// https://stackoverflow.com/questions/17362509/how-to-use-symbols-of-extended-ascii-table-in-c4
// https://stackoverflow.com/questions/26438222/print-a-filled-square-in-console
void printValueOfCell(Cell value)
{
    // unsigned char emptyCH = EMPTY_CELL_SYMBOL;
    // unsigned char fullCh = FULL_CELL_SYMBOL;
    if (value == EMPTY_CELL)
    {
        printf("\u25A1");
    }
    else if (value == FULL_CELL)
    {
        printf("\u25A0");
    }
    else
    {
        printf("!");
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

