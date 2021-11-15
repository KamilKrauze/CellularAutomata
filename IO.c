#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

    fprintf(fptr, "%d\n%s", grid1dColCount, ",");
    for (int i = 0; i < grid1dColCount; i++)
    {
        (int) gridPtr->row[i];
        fprintf(fptr, "%d\n%s", gridPtr->row[i], ",");
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
        fscanf(fptr, "%hhd\n%s", &grid->row[i],",");
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
            fprintf(fptr, "%s\n%s", &gridPtr->table[x][y], ",");
        }
        fprintf(fptr, "%s", "\n");
    }
    free2DGrid(gridPtr);
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
            fscanf(fptr, "%hhd,", &grid->table[x][y]);
        }
        fprintf(fptr, "%s", "\n");
    }
    free2DGrid(grid);
    return SUCCESS;
}