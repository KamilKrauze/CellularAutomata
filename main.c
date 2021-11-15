/**
 * Student Name: Kamil Krauze
 * Matric Number: 2414951
 * 
 */

#include <stdio.h>

#include "menu.h"
#include "binConv.h"
#include "IO.c"
#include "IO.h"

int main()
{
    int test = read1DFromFile();
    if (test == 100)
    {
        printf("%s", "Read 1D was successful");
    }
    int test1 = read2DFromFile();
    if (test1 == 100)
    {
        printf("%s", "Read 2D was successful");
    }
    // Grid1D *grid1d = initialize1DGrid(1);

    // Grid2D *grid = initialize2DGrid(1);
    int test2 = write2DToFile();
    if (test2 == 100)
    {
        printf("%s", "Write 2D was successful");
    }

    return 0;
}