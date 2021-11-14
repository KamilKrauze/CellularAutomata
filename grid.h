#include <stdbool.h>

#define SUCCESS 100
#define INVALID_INPUT_PARAMETER 101

#define PARTIAL_SUCCESS 102

#define MEMORY_ALLOCATION_ERROR 103

#define NOT_IMPLEMENTED 104
#define FILE_IO_ERROR 105

#define OUT_OF_BOUNDS 'Z'
#define EMPTY_CELL '0'
#define FULL_CELL '1'

#define EMPTY_CELL_SYMBOL 'x'
#define FULL_CELL_SYMBOL 'o'

#define COL_COUNT 15
#define ROW_COUNT 5

typedef char Cell;

typedef struct ruleset
{
    bool ruleArray[8];
} Ruleset;
typedef struct ruleset2d
{
    bool rulesetForDeadCells[9];
    bool rulesetForAliveCells[9];
} Ruleset2D;

typedef struct grid1d
{
    Cell row[COL_COUNT];
} Grid1D;

typedef struct grid2d
{
    Cell table[ROW_COUNT][COL_COUNT];
} Grid2D;

char getDisplayValueOfCell(Cell value);

bool doCellsMatch(int a, Cell b);
void printValueOfCell(Cell value);

Grid1D *initialize1DGrid(Cell defaultValue);

Grid2D *initialize2DGrid(Cell defaultValue);

int display1DGrid(Grid1D *gridPtr);

int display2DGrid(Grid2D *gridPtr);

int updateGrid1D(Grid1D *gridPtr, int column, Cell value);

int updateGrid2D(Grid2D *gridPtr, int column, int row, Cell value);

int getValueGrid1D(Grid1D *gridPtr, Cell *cellPtr, int column);

int getValueGrid2D(Grid2D *gridPtr, Cell *cellPtr, int column, int row);

int getNextGeneration1D(Grid1D *gridPtr, Ruleset ruleset, bool wrapAroundEdges);

int getNextGeneration2D(Grid2D *gridPtr, Ruleset2D ruleset, bool wrapAroundEdges);

int runSimulation1d(Grid1D *gridPtr, Ruleset ruleset, bool wrapAroundEdges, int numberOfGenerations);

int runSimulation2d(Grid2D *gridPtr, Ruleset2D ruleset, bool wrapAroundEdges, int numberOfGenerations);

int runConwaysGameOfLife(Grid2D *gridPtr, int numberOfGenerations, bool wrapEdges);