/*
 * Author: Robert Crocombe
 * Class: CS352 Summer 04
 * Assignment: HW3 problem hanoi.c
 *
 * Computes the classic Towers of Hanoi problem, whereby there are 3
 * potential locations: A, B, C, and 'n' pieces ordered from smallest
 * to largest on A that have to be moved to C and end up in the same
 * order, but at no time allowing a larger piece to be on top of a
 * smaller piece.  Prints out the moves as "src dest" for 'n' between
 * MIN and MAX.
 */

#include <stdlib.h>
#include <stdio.h>

/* More than trivial for < 1 piece -- world may end before can print moves
 * for 64 pieces. */
#define MIN 1
#define MAX 64

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void hanoi(const unsigned int n, const char src, const char dest, const char aux);

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*
 * The recursive routine that does any actual work.  The parameters
 * are 'n' (effectively what level of the problem we're at), and then
 * the names of the source, destination, and auxiliary storage space
 * towers for this level of the problem.
 *
 * Recurses to solve problem and also prints out the move for this
 * single level of the overall problem: line is the source and
 * destination towers for the piece that we need to move at this
 * level.
 */

void
hanoi(const unsigned int n, const char src, const char dest, const char aux)
{
    if (n > 0)
    {
        hanoi( n - 1, src, aux, dest);
        printf("%c %c\n", src, dest);
        hanoi( n - 1, aux, dest, src);
    }
}

/*
 * Gets the user input: how many pieces in this execution of the
 * puzzle.  Non-numerical inputs cause the program to exit with code
 * 1, while out-of-range problems cause the program to terminate with
 * code 2.  Otherwise program executes the puzzle solution and returns
 * 0.
 */

int
main
(
    int argc,
    char *argv[]
)
{
    unsigned int n;

    /* Get input. */
    int ret = scanf("%u", &n);
    if ( ret == 0 )
    {
        printf("Invalid user input. Exiting.\n");
        exit(1);
    }

    /* Test for range violations */
    if ( (n < MIN) || (n > MAX) )
    {
        printf("Out of bounds. Exiting.\n");
        exit(2);
    }

    /* Go. */
    hanoi(n, 'A', 'C', 'B');

    return 0;
}

