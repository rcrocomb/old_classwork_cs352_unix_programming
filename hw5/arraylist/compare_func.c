/* File: compare_func.c
 *
 * Marshall McMullen, TA provided file of compare functions
 * CS352 Summer 2004
 * University of Arizona
 *
 * This is the C code for some simple compare functions to aid in
 * hw5's need to specify function pointers that compare two values
 * for comparing keys and values in the hashtable.
 *
 * In your test program, just specify which compare function you
 * want to use when you initialize the hashtable.  See the example
 * in hashtable_test.c
 */

#include <string.h>
#include "compare_func.h"

/*==================================================================*
 * Function: compare_char()
 * Purpose: The purpose of this function is to provided an abstract
 *          way to compare two characters.
 * Returns: 1 if a > b
 *    0 if a == b
 *    -1 if a < b
 *==================================================================*/
int compare_char (const void *a, const void *b)
{
    char *aa = (char *) a, *bb = (char *) b;

    return (*aa - *bb);
}

/*==================================================================*
 * Function: compare_int()
 * Purpose: The purpose of this function is to provided an abstract
 *          way to compare two ints.
 * Returns: 1 if a > b
 *    0 if a == b
 *    -1 if a < b
 *==================================================================*/
int compare_int (const void *a, const void *b)
{
    int *aa = (int *) a, *bb = (int *) b;

    return (*aa - *bb);
}

/*==================================================================*
 * Function: compare_double()
 * Purpose: The purpose of this function is to provided an abstract
 *          way to compare two doubles.
 * Returns: 1 if a > b
 *    0 if a == b
 *    -1 if a < b
 *==================================================================*/
int compare_double (const void *a, const void *b)
{
    double *aa = (double *) a, *bb = (double *) b;

    return (int) (*aa - *bb);
}

/*==================================================================*
 * Function: compare_string()
 * Purpose: The purpose of this function is to provided an abstract
 *          way to compare two strings.
 * Returns: 1 if a > b
 *    0 if a == b
 *    -1 if a < b
 *==================================================================*/
int compare_string (const void *a, const void *b)
{
    if (!a && !b)
        return 0;
    else if (!a && b)
        return -1;
    else if (a && !b)
        return 1;
    else
        return strcmp (a, b);
}
