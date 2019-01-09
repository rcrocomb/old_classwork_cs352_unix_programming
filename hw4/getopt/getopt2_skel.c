/* File: getopt2_skel.c
 *
 * Marshall McMullen, TA provided skelaton file
 * CS352 Summer 2004
 * University of Arizona
 */

/* INCLUDE HEADERS */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt2.h>

/*==================== GLOBAL VARIABLES =========================*/

/* Index in ARGV of the next element to be scanned.
   This is used for communication to and from the caller
   and for communication between successive calls to `getopt'.

   On entry to `getopt', zero means this is the first call; initialize.

   Otherwise, `optind' communicates from one call to the next
   how much of ARGV has been scanned so far.  */
int optind2 = 1;                // skip over program name

/* Index to keep track of what character you are in within a group
   of options.  This way, if someone passes valid and invalid options
   all joined together, on subsequent calls, you can easily pick up
   where you left off within that string of option flags.
*/
int c_offset = 0;

/* Callers store zero here to inhibit the error message `getopt2' prints
   for unrecognized options.  */
int opterr2 = 0;                // caller sets this to 1 to turn off debugging

/* Set to an option character which was unrecognized.  */
int optopt2 = '\0';

/* char * to hold non-options strings associated with -2 return */
char *nonopt = "";

/* The get_options function parses the command line input from the
 * user based on a const char* list of valid options.  If a valid
 * match is found within the current argument, it will return that
 * character. Otherwise if the character is an _OPTION_ (meaning there
 * is a '-' at the beginning of this argument) yet did not match one
 * of the valid options passed by the user, then it will return a '?'.
 * Finally, if the argument is not an option at all (no '-' at start
 * of this argument), it will return '-1'.  Also, if it is NOT an option,
 * it returns NONOPT (-2). Ultimately, it returns EOF when all the
 * arguments on the command line have been parsed.
 */
int getopt2 (int argc, char *argv[], const char *optstring)
{

}
