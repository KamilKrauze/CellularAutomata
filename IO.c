/**
 * Team T
 * 
 * Student Name: Vojtech Loskot
 * Matric Number: 2424633
 * 
 * Student Name: Kamil Krauze
 * Matric Number: 2414951
 * 
 * Student Name: Harry Inglis
 * Matric Number: 2411653
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "IO.h"

int write1DToFile(Grid1D *gridPtr)
{
    if (gridPtr == NULL)
    {
        return INVALID_INPUT_PARAMETER;
    }
    FILE *fptr;
    fptr = fopen("saved1D.txt", "w");
    if (fptr == NULL)
    {
        return FILE_IO_ERROR;
    }

    fprintf(fptr, "%d\n%s", grid1dColCount, ",");
    for (int i = 0; i < grid1dColCount; i++)
    {
        // (int) gridPtr->row[i];
        fprintf(fptr, "%d\n%s", (int)gridPtr->row[i], ",");
    }
    fclose(fptr);
    return SUCCESS;
}

Grid1D *read1DFromFile()
{
    Grid1D *grid = initialize1DGrid(EMPTY_CELL);
    FILE *fptr;
    fptr = fopen("saved1D.txt", "r");
    int size = ftell(fptr);
    if (fptr == NULL)
    {
        printf("%s", "Failed to open file, initialising new grid");
        return grid;
    }
    if (size == 0)
    {
        printf("%s", "No grid is saved, initialising new grid");
        return grid;
    }

    fscanf(fptr, "%d", &grid1dColCount);

    for (int i = 0; i < grid1dColCount; i++)
    {
        fscanf(fptr, "%hhd\n", &grid->row[i]);
    }
    return grid;
}

int write2DToFile(Grid2D *gridPtr)
{
    if (gridPtr == NULL)
    {
        return INVALID_INPUT_PARAMETER;
    }
    FILE *fptr;
    fptr = fopen("saved2D.txt", "w");
    if (fptr == NULL)
    {
        return FILE_IO_ERROR;
    }
    fprintf(fptr, "%ls\n%ls", &grid2dRowCount, &grid2dColCount);
    for (int x = 0; x < grid2dRowCount; x++)
    {
        for (int y = 0; y < grid2dColCount; y++)
        {
            fprintf(fptr, "%s\n%s", &gridPtr->table[x][y], ",");
        }
        fprintf(fptr, "%s", "\n");
    }
    return SUCCESS;
}
Grid2D *read2DFromFile()
{
    Grid2D *grid = initialize2DGrid(EMPTY_CELL);
    FILE *fptr;
    fptr = fopen("saved2D.txt", "r");
    // int size = ftell(fptr);
    if (fptr == NULL)
    {
        printf("%s", "Failed to open file, initialising new grid");
        return grid;
    }
    // if (size == 0)
    // {
    //     printf("%s", "No grid is saved, initialising new grid");
    //     return grid;
    // }
    fscanf(fptr, "%d\n%d", &grid2dRowCount, &grid2dColCount);
    for (int x = 0; x < grid2dRowCount; x++)
    {
        for (int y = 0; y < grid2dColCount; y++)
        {
            fscanf(fptr, "%hhd,", &grid->table[x][y]);
            printf("%c", grid->table[x][y]);
        }
        // fprintf(fptr, "%s", "\n");
    }
    return grid;
}
