/* File: hashcode_func.c
 *
 * Marshall McMullen, TA provided hashcode functions
 * CS352 Summer 2004
 * University of Arizona
 *
 * This is the C code for some simple hash functions for 
 * commonly used data types, currently supporting: strings, ints, 
 * doubles, and characters.
 */

#include <hashcode_func.h>
#include <string.h>

int hash_char (const void *k, int table_size)
{

    char val_c = *(char *) k;
    int val = (int) val_c;

    return val % table_size;
}

int hash_int (const void *k, int table_size)
{

    int val = *(int *) k;

    return val % table_size;
}

int hash_double (const void *k, int table_size)
{

    double val_d = *(double *) k;
    int val = (int) val_d;

    return val % table_size;
}

int hash_string (const void *k, int table_size)
{

    int hashVal = 0;
    char *key = (char *) k;
    int len = strlen (key);

    int i;
    for (i = 0; i < len; i++)
        hashVal = 37 * hashVal + key[i];

    hashVal %= table_size;

    if (hashVal < 0)
        hashVal += table_size;

    return hashVal;
}
