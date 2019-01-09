/* File: getopt2.h
 *
 * Marshall McMullen, TA provided header file
 * CS352 Summer 2004
 * University of Arizona
 *
 * This is the header file for a custom version of getopt that is
 * portable and platform independent.
 *
 * The reason this program is needed is due to the incompatabily
 * problems in the <unistd.h> version of getopt.  <unistd.h>'s version
 * of getopt performs perfectly on Linux machines.  However, on Lectura
 * (Sun Solaris), it fails to retrieve all command line options
 * when they are separated, e.g.:
 *
 * ~./my_grep -cn "This" -i /usr/local/doc/rcs/CREDITS
 *
 * would only return -cn on Solaris, but would return -cni on Linux.
 * Thus since we need a portable solution, this program had to be
 * written.
 *
 * This program is _MEANT_ to be nearly comptabile with the standard
 * getopt version specified in <unistd.h>, with some simplifications.
 *
 * Specifically, this version does not provide the ability to have
 * command line options that themselves take options.
 *
 * Nor does it have need for the CRYPTIC : flag before the list
 * of options.  Other than those two exceptions, its
 * use should be the same.
 *
 * Also, because we all want to be cool C hackers, we are to use
 * pointer notation only instead of array notation!
 */

/* MACROS */
#define FALSE 0
#define TRUE 1
#define NONOPTION -2

/* Index in ARGV of the next element to be scanned.
   This is used for communication to and from the caller
   and for communication between successive calls to `getopt'.

   On entry to `getopt', zero means this is the first call; initialize.

   Otherwise, `optind' communicates from one call to the next
   how much of ARGV has been scanned so far.
*/
extern int optind2;

/* Index to keep track of what character you are in within a group
   of options.  This way, if someone passes valid and invalid options
   all joined together, on subsequent calls, you can easily pick up
   where you left off within that string of option flags.
*/
extern int c_offset;

/* Callers store zero here to inhibit the error message `getopt2' prints
   for unrecognized options.
*/
extern int opterr2;

/* Set to an option character which was unrecognized.  */
extern int optopt2;

/* char * to hold non-options strings associated with -2 return */
extern char *nonopt;

/* Function prototype for getopt2 */
int getopt2 (int argc, char *argv[], const char *optstring);
