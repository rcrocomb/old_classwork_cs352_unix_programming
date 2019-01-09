
/* File: hashcode_func.h
 *
 * Marshall McMullen, TA provided header file for hashcode functions
 * CS352 Summer 2004
 * University of Arizona
 *
 * This is the header file for some simple hash functions for 
 * commonly used data types, currently supporting: strings, ints, 
 * doubles, and characters.
 */

#ifndef __HASHCODE_FUNC_H
#define __HASHCODE_FUND_H

int hash_char (const void *k, int table_size);
int hash_int (const void *k, int table_size);
int hash_double (const void *k, int table_size);
int hash_string (const void *k, int table_size);

#endif
