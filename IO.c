// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>


#include "io.h"
#include "grid.h"

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

    fprintf(fptr, "%s", grid1dColCount, ",");
    for (int i = 0; i < grid1dColCount; i++)
    {
        fprintf(fptr, "%s", gridPtr->row[i], ",");
    }
    fclose(fptr);
    return SUCCESS;
}

int read1DFromFile()
{
    Grid1D *grid = initialize1DGrid(0);
    FILE *fptr;
    fptr = fopen("saved1D.txt", "r");
    if (fptr == NULL)
    {
        return FILE_IO_ERROR;
    }

    for (int i = 0; i < grid1dColCount; i++)
    {
        fscanf(fptr, "%1d,", grid->row[i]);
    }
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
    for (int x = 0; x < grid2dRowCount; x++)
    {
        for (int y = 0; y < grid2dColCount; y++)
        {
            fprintf(fptr, "%s", gridPtr->table[x][y], ",");
        }
        fprintf(fptr, "%s", "\n");
    }
    return SUCCESS;
}
int read2DFromFile()
{
    Grid2D *grid = initialize2DGrid(0);
    FILE *fptr;
    fptr = fopen("saved2D.txt", "r");
    if (fptr == NULL)
    {
        return FILE_IO_ERROR;
    }

    for (int x = 0; x < grid2dRowCount; x++)
    {
        for (int y = 0; y < grid2dColCount; y++)
        {
            fscanf(fptr, "%1d,", grid->table[x][y]);
        }
        fscanf(fptr, "%s", "\n");
    }
}
