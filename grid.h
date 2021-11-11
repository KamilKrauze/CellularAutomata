#define SUCCESS 100                 // Value to be returned if a function is completed successfully
#define INVALID_INPUT_PARAMETER 101 // Value to be returned if you detect that one of the input parameters \
                                    // into your function is invalid, e.g. it is NULL or an unexpected value
#define PARTIAL_SUCCESS 102         // Value to return if there has been only partial success in adding a collection \
                                    // of edges to a graph, i.e., some were added, some were not.
#define MEMORY_ALLOCATION_ERROR 103 // Value to be returned if your function detects an operation that is being     \
                                    // attempted on your list data structure isn't valid or your list               \
                                    // isn't in a ready state to receive. For example, an attempt is made to remove \
                                    // an item from an empty list
#define NOT_IMPLEMENTED 104         // Value to be returned if you haven't implemented this function yet
#define FILE_IO_ERROR 105           // May be required for some File IO tasks. E.g. failure to open a file.

#define ROW_SIZE 50

typedef char Cell;

typedef struct grid1d
{
    Cell row[ROW_SIZE];
} Grid1D;

typedef struct grid2d
{
    Cell row[ROW_SIZE][ROW_SIZE];
} Grid2D;

Grid1D *initialize1DGrid(Cell defaultValue);

Grid2D *initialize2DGrid(Cell defaultValue);

int display1DGrid(Grid1D *gridPtr);

int display2DGrid(Grid2D *gridPtr);

int updateGrid1D(Grid1D *gridPtr, int column, Cell value);

int updateGrid2D(Grid2D *gridPtr, int column, int row, Cell value);

Cell getValueGrid1D(Grid1D *gridPtr, int column);

Cell getValueGrid2D(Grid2D *gridPtr, int column, int row);


