/*!
    Author: Robert Crocombe
    Class: CS352 Summer 04
    Assignment: HW4 abspath.c

    This program will, given an input string, translate that string as
    if it were a directory relative to the current directory and print
    the resulting absolute path.  Therefore strings beginning with "/"
    are already absolute, and so are returned untranslated.  The
    program does *not* check the validity of the resulting directory
    name.
*/

#include <stdio.h>
#include <unistd.h>             /* getcwd() */
#include <string.h>             /* strlen(), strcpy(), memcpy(), etc.*/
#include <stdlib.h>             /* malloc(), exit(), free() */
#include <limits.h>             /* PATH_MAX */

/******************************************************************************/
/* Macros                                                                     */
/******************************************************************************/

/* Used with getcwd() */
#define BUFSIZE 50

/* Useful for free(), which doesn't like NULL pointers. */
#define SMART_FREE(a) do { if((a)) free((a)); (a) = NULL; } while(0);

/* Random error numbers for various potential problems */
#define PATH_ERR -42
#define MALLOC_ERR -17

/******************************************************************************/
/* Prototypes                                                                 */
/******************************************************************************/

void abspath(const char * const in);

/******************************************************************************/
/* Definitions                                                                */
/******************************************************************************/

/*!
    abspath is the routine doing the heavy lifting of the program.  Only
    already absolute paths are recognized in main, so this function must
    do the translation given strings like ".././././../monkey/.././", etc.

    If you do something like:

        cd /; abspath .////////////////////////

    then you will get

        /////////////////////////

    (or therebouts) as your result.  This is correct, but a bit
    abstruse or whatever.  You can do:

        cd /////////////////////////

    and get taken to the right spot. I aitn't stripping the redundant "//"s.
    Similar can happen with non "/" directories.

        $ cd /home/rcrocomb/class/cs352/hw4/abspath/
        $ ./path .//
        /home/rcrocomb/class/cs352/hw4/abspath//            <--- NOTE
        $ cd /home/rcrocomb/class/cs352/hw4/abspath//
        $ pwd
        /home/rcrocomb/class/cs352/hw4/abspath

    which is correct!  Yay!

    Should handle ' ', '.', '!', etc. as long as they are quoted properly.
*/

void
abspath(const char * const in)
{
    char *out = NULL;           /* output: absolute path goes here */
    char *temp = NULL;
    const char *travel = NULL;  /* travel and trail move through input string */
    const char *trail = NULL;
    unsigned int length = 0;
    unsigned int length_original = 0;
    unsigned int bufsize = BUFSIZE; /* buffer size for getcwd() buffer */

    travel = trail = in;

    /* Get current directory.  No wonder getcwd() is deprecated. */
    do
    {
        out = (char *)malloc(bufsize + 1);
        temp = getcwd(out, bufsize);
        if ( temp == NULL)
        {
            SMART_FREE(out);
            if (bufsize >= PATH_MAX)
            {
                fprintf(stderr, "Can't malloc big enough string.\n");
                exit(PATH_ERR);
            }
            bufsize *= 2;
        }
    } while (temp == NULL);

    /* Go through the input string */
    while ( *trail != '\0')
    {
        if ( (travel[0] == '.') && (travel[1] == '.') && (travel[2] == '/'))
        {
            /* Skip past "../" in the input string */
            trail = travel += strlen("../");

            /* Chop last element off output string (if possible) */
            temp = strrchr(out, '/');
            if ( temp == NULL)
            {
                /* I don't think this can ever happen */
                strcpy(out, "/");   /* Smallest possible path, so must fit */
            } else
            {
                /* Chop off last element */
                length = temp - out;
                if ( length == 0)
                {
                    strcpy(out, "/");/* Smallest possible path, so must fit */
                } else
                {
                    /* Reallocate new string for chopped string */
                    /* I suppose this isn't strictly necessary, but... */
                    temp = (char *)malloc(length + 1);
                    memcpy(temp, out, length);
                    temp[length] = '\0';
                    SMART_FREE(out);
                    out = temp;
                }
            }
        }
        else if ( (travel[0] == '.') && (travel[1] == '/'))
        {
            /* "./" is a no-op: just skip it in input string */
            trail = travel += strlen("./");
        }
        /* The test of trail is to prevent barfing on "//". */
        else if (   ((travel[0] == '/') && (trail[0] != '/'))
                 || (travel[0] == '\0'))
        {
            length = travel - trail;
            length_original = strlen(out);

            /* room for '\0' and missing '/' */
            temp = (char *)malloc(length + length_original + 2);
            if (temp == NULL)
            {
                fprintf(stderr, "Malloc failed.\n");
                exit(0);
            }

            memcpy(temp, out, length_original);

            /* I gave up trying to figure out the logic about when or
             * where to have a damn '/': sometimes I was getting:
             *  /blah/de/dah//darn  <-- doubled up '/'
             *
             *  and sometimes
             *
             * /blah/de/dah/darn/   <-- trailing '/'
             *
             * Depending upon whether I had trail always behind travel
             * or right on it, like now.  I mean, both answers will go
             * to the right place, but they'll look wrong in a simple
             * diff.
             */
            if ( (temp[length_original-1] != '/') && (*trail != '/'))
            {
                temp[length_original] = '/';
                memcpy(temp + length_original + 1, trail, length);
                temp[length + length_original + 1] = '\0';
            } else
            {
                memcpy(temp + length_original, trail, length);
                temp[length + length_original] = '\0';
            }
            SMART_FREE(out);

            out = temp;
            travel += (*travel == '/');
            trail = travel;
        }
        else
        {
            /* Skipping through directory name */
            ++travel;
        }
    }

    /* Done */
    printf("%s\n", out);
}

/*!
    If there is a path argument to absolute-ify that is
    non-absoluteified currrently, then call abspath(), else if there
    is no argument, quit, else print pre-absoluteified path.  But not
    in that order.
*/

int
main
(
    int argc,
    char *argv[]
)
{
    if ( argv[1] != NULL )
    {
        if ( *argv[1] == '/')
        {
            printf("%s\n", argv[1]);
        } else
        {
            abspath(argv[1]);
        }
    }

    return 0;
}

