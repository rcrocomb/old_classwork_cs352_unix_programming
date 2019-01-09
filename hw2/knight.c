/*******************************************************************************
* Author: Robert Crocombe                                                      *
* Class: CS352                                                                 *
* Assignment: HW#2 'knight.c'                                                  *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include <stdio.h>                      // printf(), scanf()
#include <stdlib.h>                     // exit()

/*******************************************************************************
* Macros                                                                       *
*******************************************************************************/

#define TRUE 1
#define FALSE 0

/*******************************************************************************
* Typedefs                                                                     *
*******************************************************************************/

typedef unsigned int boolean;

/*
    To be able to draw the board in one pass, it is important that the
    moves be orderd in this way: all the moves that could result in a position
    on a given row must be in order from left to right, with moves to
    lower (higher numbered) rows occuring after those of earlier rows.
*/
enum knight_move_t { UP_LEFT, UP_RIGHT, LEFT_UP, RIGHT_UP,
                     LEFT_DOWN, RIGHT_DOWN, DOWN_LEFT, DOWN_RIGHT };

struct move_struct
{
    unsigned int x;
    unsigned int y;
};


/*******************************************************************************
* Constants                                                                    *
*******************************************************************************/

static const unsigned int MIN_SIZE = 5;
static const unsigned int MAX_SIZE = 20;
static const unsigned int MAX_KNIGHT_MOVES = 8;
static const unsigned int SQUARE_SIZE = 3;

static const char START_CHAR    = '+';
static const char DIVIDER_CHAR  = '|';
static const char KNIGHT_CHAR   = 'K';
static const char MOVE_CHAR     = '*';
static const char EMPTY_CHAR    = ' ';

/*******************************************************************************
* Prototypes                                                                   *
*******************************************************************************/

boolean check_boundaries ( const int x,
                           const int y,
                           const unsigned int max);

boolean move_knight ( const enum knight_move_t move_type,
                      unsigned int * const x,
                      unsigned int * const y,
                      const unsigned int max_dimension);

void draw_top(const unsigned int size);

void draw_bottom (const unsigned int size);

void draw_a_square(const char c);

void draw_board(const unsigned int board_dimension,
                const unsigned int knight_x,
                const unsigned int knight_y);

/*******************************************************************************
* Definitions                                                                  *
*******************************************************************************/

/*
    Returns true if a knight's move results in a legal position (within the
    confines of the board, or false if it doesn't.
*/

boolean
check_boundaries
(
    const int x,
    const int y,
    const unsigned int max
)
{
    return ( (x >= 0) && (x < max) && (y >= 0) && (y < max) );
}

/*
    Checks to see if, given a knight at positions 'x' and 'y', it can
    successfully complete a move of type 'move_type' on a board with
    dimensions 'max_dimension'.  Returns TRUE or FALSE as appropriate,
    and if TRUE, puts the resulting position in 'x' and 'y'.
*/

boolean
move_knight
(
    const enum knight_move_t move_type,
    unsigned int * const x,
    unsigned int * const y,
    const unsigned int max_dimension
)
{
    int new_x = *x;
    int new_y = *y;
    boolean status = FALSE;

    switch( move_type)
    {
    case LEFT_UP:   new_x -= 2; new_y -= 1; break;
    case UP_LEFT:   new_x -= 1; new_y -= 2; break;
    case UP_RIGHT:  new_x += 1; new_y -= 2; break;
    case RIGHT_UP:  new_x += 2; new_y -= 1; break;
    case LEFT_DOWN: new_x -= 2; new_y += 1; break;
    case DOWN_LEFT: new_x -= 1; new_y += 2; break;
    case DOWN_RIGHT:new_x += 1; new_y += 2; break;
    case RIGHT_DOWN:new_x += 2; new_y += 1; break;
    default:
        printf("Unknown knight move type: %u!\n", move_type);
        return status;
    }

    status = check_boundaries(new_x, new_y, max_dimension);
    if ( status )
    {
        *x = new_x;
        *y = new_y;
    }
    return status;
}

/*
    Draws the divider between the tops of each square.  Should scale if
    SQUARE_SIZE changes.  'size' is the size of the board.
*/

void
draw_top(const unsigned int size)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int stop;

    for ( ; i < size; i++)
    {
        printf("%c", START_CHAR);
        stop = (i+1) * SQUARE_SIZE + 1;
        for (j = i * SQUARE_SIZE + 1; j < stop; j++)
        {
            printf("-");
        }
    }
    printf("%c\n", START_CHAR);
}

/*
    Same as draw_top(): just easier to remember for the bottom of the board.
*/

void
draw_bottom(const unsigned int size)
{
    draw_top(size);
}

/*
    Should scale correctly if SQUARE_SIZE changes.  Draws the "insides" of
    each square on the chess board, including the proper interior elements
    if they are passed into 'c' correctly.
*/

void
draw_a_square(const char c)
{
    unsigned int i = 0;
    for( ; i < (SQUARE_SIZE >> 1); i++)
    {
        printf(" ");
    }
    printf("%c", c);
    ++i;
    for( ; i < SQUARE_SIZE; i++)
    {
        printf(" ");
    }
}

/*
    Given a chess board with dimensions board_dimension x board_dimension
    and a knight positioned at (knight_x, knight_y) with the upper left hand
    corner as (1,1), draw a 'K' at the knight's position and a '*' at the
    position of any legal moves (stay within board) the knight may make.
*/

void
draw_board
(
    const unsigned int board_dimension,
    const unsigned int knight_x,
    const unsigned int knight_y
)
{
    unsigned int count = 0;
    unsigned int row = 0;
    unsigned int col = 0;
    unsigned int index = 0;
    unsigned int drawn_index = 0;
    struct move_struct knight_moves[MAX_KNIGHT_MOVES];

    /* Record which moves of the knight are legal. */

    for ( ; count < MAX_KNIGHT_MOVES; count++ )
    {
        knight_moves[index].x = knight_x;
        knight_moves[index].y = knight_y;
        if ( move_knight( count, /* using an integer as a knight_move_t */
                          &(knight_moves[index].x),
                          &(knight_moves[index].y),
                          board_dimension )
        )
        {
            ++index;
        }
    }

    /* Draw the board row-wise. */

    for ( row = 0 ; row < board_dimension; row++)
    {
        draw_top(board_dimension);
        for ( col = 0; col < board_dimension; col++)
        {
            printf("%c", DIVIDER_CHAR);
            if (   (knight_moves[drawn_index].x == col)
                && (knight_moves[drawn_index].y == row))
            {
                draw_a_square(MOVE_CHAR); /* Knight can move here OK */
                ++drawn_index;
            }
            else if ( (col == knight_x) && (row == knight_y) )
            {
                draw_a_square(KNIGHT_CHAR); /* Square contains the knight */
            }
            else
            {
                draw_a_square(EMPTY_CHAR); /* Nothing happening */
            }
        }
        printf("%c\n", DIVIDER_CHAR);
    }

    draw_bottom(board_dimension);
}

int
main
(
    int argc,
    char *argv[]
)
{
    int x, y, board_dimension, ret;

    /* Get the board's size and check for correctness */

    printf("Board size: ");
    ret = scanf("%d", &board_dimension);
    if ( ret != 1 )
    {
        printf("Invalid user input.  Exiting.\n");
        exit(1);
    } else if ( (board_dimension < MIN_SIZE) || (board_dimension > MAX_SIZE) )
    {
        printf("Invalid board size.  Exiting.\n");
        exit(2);
    }

    /* Get the column position of the knight and check for correctness */

    printf("Knight row: ");
    ret = scanf("%d", &y);
    if ( ret != 1 )
    {
        printf("Invalid user input.  Exiting.\n");
        exit(1);
    } else if ( (y < 1) || (y > MAX_SIZE) )
    {
        printf("Invalid knight position.  Exiting.\n");
        exit(3);
    }

    /* Get the row position of the knight and check for correctness */

    printf("Knight column: ");
    ret = scanf("%d", &x);
    if ( ret != 1 )
    {
        printf("Invalid user input.  Exiting.\n");
        exit(1);
    } else if ( (x < 1) || (x > MAX_SIZE) )
    {
        printf("Invalid knight position.  Exiting.\n");
        exit(3);
    }

    /* My positions are zero based: user input is apparently 1-based */
    draw_board( board_dimension, x - 1, y - 1);

    return 0;
}

