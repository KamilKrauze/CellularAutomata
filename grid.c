/**
 * Student Name: Vojtech Loskot
 * Matric Number: 2424633
 * 
 */
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
        // printf(" ");
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

int displayRuleset1D(Ruleset ruleset)
{
    printf("\nRuleset: \n");

    printf(" ");
    printValueOfCell(FULL_CELL);
    printValueOfCell(FULL_CELL);
    printValueOfCell(FULL_CELL);
    printf(" ");
    //
    printf(" ");
    printValueOfCell(FULL_CELL);
    printValueOfCell(FULL_CELL);
    printValueOfCell(EMPTY_CELL);
    printf(" ");
    //
    printf(" ");
    printValueOfCell(FULL_CELL);
    printValueOfCell(EMPTY_CELL);
    printValueOfCell(FULL_CELL);
    printf(" ");
    //
    printf(" ");
    printValueOfCell(FULL_CELL);
    printValueOfCell(EMPTY_CELL);
    printValueOfCell(EMPTY_CELL);
    printf(" ");
    //
    printf(" ");
    printValueOfCell(EMPTY_CELL);
    printValueOfCell(FULL_CELL);
    printValueOfCell(FULL_CELL);
    printf(" ");
    //
    printf(" ");
    printValueOfCell(EMPTY_CELL);
    printValueOfCell(FULL_CELL);
    printValueOfCell(EMPTY_CELL);
    printf(" ");
    //
    printf(" ");
    printValueOfCell(EMPTY_CELL);
    printValueOfCell(EMPTY_CELL);
    printValueOfCell(FULL_CELL);
    printf(" ");
    //
    printf(" ");
    printValueOfCell(EMPTY_CELL);
    printValueOfCell(EMPTY_CELL);
    printValueOfCell(EMPTY_CELL);
    printf(" ");
    //
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        if (ruleset.ruleArray[i])
        {
            printf("  ");
            printValueOfCell(FULL_CELL);
            printf("  ");
        }
        else
        {
            printf("  ");
            printValueOfCell(EMPTY_CELL);
            printf("  ");
        }
    }
    printf("\n");

    for (int i = 0; i < 8; i++)
    {

        printf("  %d  ", ruleset.ruleArray[i]);
    }
    printf("\n");
    printf("\n");
    return SUCCESS;
}
void helperDisplayFunction(bool ruleArray[9])
{
    printf("\nNumber of adjacent cells:");

    for (int i = 0; i < 9; i++)
    {
        printf(" %d ", i);
    }
    printf("\nResult:                  ");
    for (int i = 0; i < 9; i++)
    {
        printf(" %d ", ruleArray[i]);
    }
    printf("\n");
}

int displayRuleset2D(Ruleset2D ruleset)
{
    printf("\nRuleset for living cells: \n");

    helperDisplayFunction(ruleset.rulesetForAliveCells);

    printf("\nRuleset for dead cells: \n");

    helperDisplayFunction(ruleset.rulesetForDeadCells);

    return SUCCESS;
}

bool conwaysGameOfLifeRules[2][9] = {
    {0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0},
};

Ruleset2D *initialize2DRuleset()
{

    Ruleset2D *ruleset2D = (Ruleset2D *)malloc(sizeof(Ruleset2D));
    if (ruleset2D == NULL)
    {
        printf("MEMORY ALLOCATION ERROR");
        return NULL;
    }
    for (int i = 0; i < 8; i++)
    {
        ruleset2D->rulesetForDeadCells[i] = conwaysGameOfLifeRules[0][i];
        ruleset2D->rulesetForAliveCells[i] = conwaysGameOfLifeRules[1][i];
    }
    return ruleset2D;
}
