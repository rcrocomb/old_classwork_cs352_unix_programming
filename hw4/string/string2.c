/*
    Author: Robert Crocombe
    Class: CS352
    Assignment: HW4 string2.c

    Implements various string operations as specified.

    Since unspecified, using array-like syntax where seemed clearer.
*/

#include "string2.h"

#include <string.h>                 /* strlen(), memcpy(), etc. */
#include <stdlib.h>                 /* malloc() */
#include <ctype.h>                  /* isspace() */

#define NUM_BASE  10                /* Base 10 numbers */

#include <stdio.h>

/*!
    Converts a signed integer to a string.
*/

char *
itoa( int num)
{
    unsigned int count = 0;
    char *result = NULL;
    int copy = num;
    unsigned int modulo = NUM_BASE;
    int length = -2; /* Takes care of terminating null && negative sign */

    /* Blah, handle 0 as a special case since it's so irritating */
    if (num == 0)
    {
        result = (char *)malloc(1 + 1);
        if (result != NULL)
        {
            result[0] = '0';
            result[1] = '\0';
        }
        return result;
    }

    /* Find out how long this number is */
    while (copy)
    {
        ++count;
        copy /= NUM_BASE;
    }

    if (num < 0)
    {
        ++length;
        ++count;        /* allocate space for '-' */
    }

    ++count;            /* allocate space for '\0' */

    /* Copy */
    result = (char *)malloc(count);
    if (result != NULL)
    {
        result[count] = '\0';
        length += count;
        count = 0;
        if (num < 0)
        {
            result[count] = '-';
            ++count;
        }

        /* We're getting the values from least to most significant,
         * so we need to reverse the way we write the string. */
        while (num)
        {
            result[length - count] = '0' + (abs(num) % modulo);
            num /= NUM_BASE;
            ++count;
        }
    }

    return result;
}

/*
    Takes the spaces out of a string (squishing characters together)
    and returns this squished together string.
*/

char *
rem_spaces(char *str)
{
    char *copy_to = NULL;
    char *copy_from = str;
    char *dest = NULL;
    unsigned int length = 0;

    if (str == NULL)
    {
        return NULL;
    }

    /* Count spaces */
    while ( *copy_from )
    {
        length += *copy_from != ' ';
        ++copy_from;
    }
    copy_from = str;

    dest = (char *)malloc(length + 1);
    if ( dest == NULL)
    {
        return NULL;
    }

    copy_to = dest;
    while ( *copy_from )
    {
       if ( isspace(*copy_from) )
       {
            ++copy_from;
       } else
       {
            *copy_to = *copy_from;
            ++copy_to;
            ++copy_from;
       }
    }
    *copy_to = '\0';
    return dest;
}

/*!
    Concatenates src to the end of dest in a new string.  Returned in
    the "char **" and via the return "char *": dest is freed.
*/

char *
strcat2(char **dest, char *src)
{
    unsigned int new_length = 0;
    char *result = NULL;
    unsigned int length_dest = 0, length_src = 0;

    /* We canna take any moore, Keptin! */
    if ( (dest == NULL) || (src == NULL) || (*dest == NULL))
    {
        return NULL;
    }

    length_dest = strlen(*dest);
    length_src = strlen(src);

    /* Allocate memory for new string. */
    new_length = length_dest + length_src + 1;
    result = (char *)malloc(new_length);
    if (result == NULL)
    {
        return NULL;
    }

    /* Copy dest to new string, first, then src. The null terminate result. */
    memcpy(result, *dest, length_dest);
    memcpy(result + length_dest, src, length_src);
    result[new_length] = '\0';

    /* Necesssary to keep from leaking memory. */
    free(*dest);

    *dest = result;
    return result;
}

/*!
    Makes a copy of src in a new string and returns it, or NULL if bad
    things happen.
*/

char *
strcpy2(char * src)
{
    char *copy = NULL;
    unsigned int length = 0;
    if (src == NULL)
    {
        return NULL;
    }

    /* Allocate new string */
    length = strlen(src);
    copy = (char *)malloc(length + 1);
    if ( copy == NULL )
    {
        return NULL;
    }

    /* Copy: could get the terminating NULL, too, but whateva' */
    memcpy(copy, src, length);
    copy[length] = '\0';
    return copy;
}

/*!
    Adds 'c' to the end of 'dest': allocates new dest to do this:
    existing dest is free()d.

    Returns NULL if there is a problem.
*/

char *
append(char **dest, char c)
{
    char *result = NULL;
    int length = 0;

    if ( (dest == NULL) || (*dest == NULL))
    {
        return NULL;
    }

    /* Allocate new string one char bigger */
    length = strlen(*dest);
    result = (char *)malloc(length + 1 + 1);
    if (result == NULL)
    {
        return NULL;
    }

    /* Copy and append */
    memcpy(result, *dest, length);
    result[length] = c;
    result[length + 1] = '\0';

    return result;
}

/*
    Given a string with a bunch of characters, some of them separated
    by spaces, return an array of strings, each string of which
    contains one of the space-delimited bunch of characters.  This
    array will be terminated by a NULL pointer

    Returns NULL on error.
*/

char **
split(char *input)
{
    char **result = NULL;
    char *travel = input;
    char *trail = NULL;
    unsigned int count = 0;
    unsigned int position = 0;

    /* No option string */
    if ( input == NULL )
    {
        return NULL;
    }

    /* Count how many separate options */
    while (1)
    {
        /* Skip whitespace */
        while ( isspace(*travel) && *travel)
        {
            ++travel;
        }

        /* If ran off end of string: done */
        if ( *travel == '\0')
        {
            break;
        }

        ++count;

        /* Find end of this option within overall string */
        while( !isspace(*travel) && *travel)
        {
            ++travel;
        }

        /* If ran off end of string, done */
        if ( *travel == '\0')
        {
            break;
        }
    }

    /* Allocate space for option strings */
    result = (char **)malloc(sizeof(char *) * count + 1);
    if (result == NULL)
    {
        return NULL;
    }

    /* Terminate array */
    result[count] = NULL;

    /* Get individual options */
    trail = travel = input;
    position = 0;
    while (position < count)
    {
        /* Find start of option */
        while ( isspace(*travel) && *travel)
        {
            ++travel;
        }

        /* Remember start */
        trail = travel;

        /* Find end of option, but don't fall off end */
        while (*travel && !isspace(*travel))
        {
            ++travel;
        }

        /* Allocate space for this option string*/
        result[position] = (char *)malloc(travel - trail + 1);
        if (result[position] == NULL)
        {
            /* Dang: no memory with stuff partially read in.  Free
             * partially read in stuff and then array of pointers and
             * quit. */
            count = 0;
            while (count < position)
            {
                free(result[count]);
                ++count;
            }
            free(result);
            return NULL;
        }

        /* Copy this option string*/
        memcpy(result[position], trail, travel - trail);
        memcpy(result[position] + (travel - trail), "\0", 1);

        /* Advance */
        ++travel;
        ++position;
    }

    return result;
}

#if 0
int
main
(
    int argc,
    char *argv[]
)
{
    return 0;
}
#endif
