/*******************************************************************************
* Author: Robert Crocombe                                                      *
* Class: CS352                                                                 *
* Assignment: Hw #2 'mitsubishi.c'                                             *
*                                                                              *
* Draws the Mitsubishi logo in ASCII using '*'s, to stdout.                    *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>                 // exit()
#include <math.h>                   // ceil()

/*******************************************************************************
* Prototypes                                                                   *
*******************************************************************************/

void top_of_top_diamond(const unsigned int n, const unsigned int total_width);
void bottom_of_top_diamond(const unsigned int n,
                           const unsigned int total_width);
void top_diamond(const unsigned int n);
inline void leg_stars(const unsigned int left, const unsigned int right);
void legs(const unsigned int n);

/*******************************************************************************
* Constants                                                                    *
*******************************************************************************/

static const unsigned int MIN_N = 2;
static const unsigned int MAX_N = 30;


/*******************************************************************************
* Definitions                                                                  *
*******************************************************************************/

/*
    Draws the top half of the top diamond of the logo: the first 'n' lines.
    Lines start one '*' wide, then are two '*'s wider for each successive
    line.

    'n' is the critical dimension of the logo.
    'total_width' is the total width of the logo as calculated from 'n'.
*/

void
top_of_top_diamond(const unsigned int n, const unsigned int total_width)
{
    unsigned int i = 0;
    unsigned int j;
    unsigned int star_offset;
    unsigned int star_width;

    /* For each line in top of diamond */
    for ( ; i < n; i++ )
    {
        /* Start printing stars at this offset: divide by two because of
         * symmetry.  Print " " until we get to that offset. */
        star_offset = ceil( (total_width / 2) - i);
        for( j = 0; j < star_offset; j++)
        {
            printf(" ");
        }

        /* Now print from star_start until total width of stars: 1 on
         * the first line, two more for each additional line: 1, 3, 5, etc.*/
        star_width = 2 * i + 1 + star_offset;
        for( ; j < star_width; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

/*
    Draws the lower half (-ish) of the upper diamond of the logo: all lines
    after the first "n".

    'n' is the critical dimension of the logo.
    'total_width' is the total width of the logo as calculated from 'n'.
*/

void
bottom_of_top_diamond(const unsigned int n, const unsigned int total_width)
{
    // bottom of top
    int i = n - 2;
    int j;
    unsigned int star_offset;
    unsigned int star_width;

    for ( ; i >=  0; i-- )
    {
        star_offset = ceil( (total_width / 2) - i);
        for( j = 0; j < star_offset; j++)
        {
            printf(" ");
        }

        star_width = 2 * i + 1 + star_offset;
        for( ; j < star_width; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

/*
    Draws the entirety of the top diamond of the Mitsubishi logo.

    'n' is the critical dimension of the logo.
*/

void
top_diamond(const unsigned int n)
{
    const unsigned int total_width = 4 * n - 1;

    top_of_top_diamond(n, total_width);
    bottom_of_top_diamond(n, total_width);
}

/*
    Given the left and right boundaries, draws the "*"s in the legs of
    the Mitsubishi logo.
*/

void
leg_stars(const unsigned int left, const unsigned int right)
{
    unsigned int i = left;
    for ( ; i < right; i++)
    {
        printf("*");
    }
}

/*
    Draws the two lower "leg" diamonds of the logo.

    The vertical symmetry accounts for the use of "*2" in several instances.
*/


void
legs(const unsigned int n)
{
    /* The width of a single "leg" of the logo. */
    const int leg_width = 2 * n - 1;
    /* i iterates over the height of each leg
     * j iterates over the width of the logo
     * k holds the positions where we should switch from ' ' to '*' */
    unsigned int i, j, k;

    for( i = 0; i < n; i++)
    {
        /* Left diamond */

        k = leg_width - i - n;
        for( j = 0; j < k ; j++)
        {
            printf(" ");
        }

        leg_stars(j, j + n);

        printf(" ");                    /* The single space between legs */

        /* Right diamond */

        k = j + 2 * i;
        for( ; j < k ; j++)
        {
            printf(" ");
        }

        leg_stars(j, j + n);

        printf("\n");
    }
    printf("\n");
}

int
main
(
    int argc,
    char *argv[]
)
{
    unsigned int n;

    int ret = scanf("%u", &n);
    if ( ret == 0 )
    {
        printf("Invalid user input.  Exiting.\n");
        exit(1);
    }

    if ( (n < MIN_N) || (n > MAX_N) )
    {
        printf("Out of bounds.  Exiting.\n");
        exit(2);
    }

    top_diamond(n);
    legs(n);

    return 0;
}

