/*!
    Author: Robert Crocombe
    Class: CS352 Summer 04
    Assignment: HW4 getopt2.c

    Implements a limited subset of the functionality of the getopt() routine,
    but provides some enhanced functionality from the standard SYSVR4
    getopt() by allowing options to be mixed with non-options, e.g.

    ./some_command -X some_stuff -y some_other_stuff ... and so forth
*/

#include "getopt2.h"

#include <stdlib.h>         /* exit() */
#include <string.h>         /* strchar() */
#include <stdio.h>          /* printf() */

/******************************************************************************/
/* Macros                                                                     */
/******************************************************************************/

#define UNKNOWN_OPTION -42
#define DELIMITER '-'

/******************************************************************************/
/* Globals                                                                    */
/******************************************************************************/

int optind2;
int opterr2 = 1;
int optopt2;
int c_offset;
char *nonopt;

/******************************************************************************/
/* Prototypes                                                                 */
/******************************************************************************/

void error(const int errcode);

/******************************************************************************/
/* Definitions                                                                */
/******************************************************************************/

/*!
    If opterr2 is set, prints an error message associated with various
    invalid states.

    (a) EOF --
*/

void
error(const int errcode)
{
    if (!opterr2)
    {
        return;
    }

    switch(errcode)
    {
        case UNKNOWN_OPTION:
            fprintf(stderr, "Unknown or unsupported option.\n");
            break;
        case NONOPTION:
            fprintf(stderr, "Invalid option character found.\n");
            break;
    }
}

/*!
    Implements a subset of getopt() functionality.

    argc and argv have their usual senses: they are the count of the
    number of commandline arguments and pointers there to,
    respectively.

    optstring is a string of characters, each of which represents a
    potential commandline argument.

    For each character of every string in argv that starts with
    DELIMITER, check to see if there exists a character in optstring
    that corresponds.  If not, then put the bad option character in
    optopt2 and return '?', otherwise return the correct option
    character.  If a non-DELIMITED string is passed, NONOPTION is
    returned and the non-option string is pointed to by nonopt.

    Between calls, getopt2() keeps track of its place, so if it is
    looped over, then it will continue from its stopping point and no
    re-parse previous commandline options.

    Hitting the end of argv causes us to return EOF.
*/

int
getopt2(int argc, char *argv[], const char *optstring)
{
    /* I used this instead of c_offset. */
    static char *pos = NULL;

    char result;
    char **save = argv;
    int i;

    /* Do not search executable name */
    --argc;

    /* All kinds of stuff gives us grief. */
    if ( (argc <= 0) || (argv == NULL) || (optstring == NULL) || (optind2 == argc))
    {
        return EOF;
    }

    /* Do here instead of above to avoid un-NULLing. */
    ++argv;

    /* Start off wherever we were (if starting a new string) */
    argv += optind2;
    nonopt = NULL;

    /* While not at end of array of arguments */
    if (*argv != NULL)
    {
        /* If was at end of string or NULL, get new string */
        if ( !pos || (pos && (*pos == '\0')) )
        {
            pos = *argv;
        }

        /* Find strings that are valid and begin with DELIMITER */
        if( **argv == DELIMITER)
        {
            /* Skip over DELIMITER */
            pos += (*pos == DELIMITER);

            /* Look for option character in our string of possibilities . */
            for ( i = 0; (i < strlen(optstring)) && (*pos != optstring[i]); ++i)
            {
                /* Nothin' -- it's in the loop header */
            }

            /* Did not find any option characters, but yet had DELIMITER */
            if (i == strlen(optstring))
            {
                error(UNKNOWN_OPTION);
                optopt2 = *pos;
                ++pos;
                /* If hit end of string -- move to next*/
                argv += (*pos == '\0');
                result = '?';
            } else
            {
                /* Found good option */
                result = *pos;
                ++pos;
                /* If hit end of string -- move to next*/
                argv += (*pos == '\0');
            }

        } else
        {
            /* String didn't start w/ DELIMITER, so non-option argument */
            error(NONOPTION);
            nonopt = pos;
            pos = NULL;
            ++argv;
        }
    }

    /* Keep track of which string we're looking at. */
    optind2 = argv - save - 1;

    /* String that doesn't start with DELIMITER */
    if (nonopt != NULL)
    {
        result = NONOPTION;
    } else if (pos == NULL)
    {
        result = EOF;
    }

    return result;
}

