#ifndef __PRINT_FUNC_H
#define __PRINT_FUNC_H

/*=============== ARRAYLIST PRINT FUNCTIONS ===================*/
void print_s (const void *a);   /* string val */
void print_i (const void *a);   /* int val */
void print_d (const void *a);   /* double val */
void print_c (const void *a);   /* char val */

/*====================== HT: STRING KEYS ======================*/
int print_s_c (const void *a);  /* char val */
int print_s_i (const void *a);  /* int val */
int print_s_d (const void *a);  /* double val */
int print_s_s (const void *a);  /* string val */

/*====================== HT: INT KEYS ======================*/
int print_i_c (const void *a);  /* char val */
int print_i_i (const void *a);  /* int val */
int print_i_d (const void *a);  /* double val */
int print_i_s (const void *a);  /* string val */

/*====================== HT: DOUBLE KEYS ======================*/
int print_d_c (const void *a);  /* char val */
int print_d_i (const void *a);  /* int val */
int print_d_d (const void *a);  /* double val */
int print_d_s (const void *a);  /* string val */

/*====================== HT: CHAR KEYS ======================*/
int print_c_c (const void *a);  /* char val */
int print_c_i (const void *a);  /* int val */
int print_c_d (const void *a);  /* double val */
int print_c_s (const void *a);  /* string val */

#endif
