/*
    Author: Robert Crocombe
    Class: CS352 Summer 04
    Assignment: HW3

    This is a re-implementation of the standard Unix-alike 'wc'
    command, except without all the fancy-schmancy options.
*/

#include <stdio.h>                  /* fprintf() */
#include <stdlib.h>                 /* exit() */
#include <ctype.h>                  /* isspace(), etc. */
#include <sys/stat.h>               /* stat() stuff */

/*******************************************************************************
* Macros
*******************************************************************************/

#define MAX_FILES 1
#define LINE_SIZE 80

#define ERR_TOO_MANY_FILES  1
#define ERR_FILE_ERR        2
#define ERR_OK              0

/*******************************************************************************
* Prototypes
*******************************************************************************/

static void usage(void);

/*******************************************************************************
* Definitions
*******************************************************************************/

/*!
    Prints out simple usage information for the program.
*/

void
usage(void)
{
    printf ("Usage: wc2 [FILE]\n");
}

/*
    Computes the number of newlines and words in the file pointed to
    by 'file'.  Returns these values in *newlines and *words,
    respectively.

    Program will terminate if there are errors while reading the file.

    assumes sizeof(char) == 1
*/

unsigned int
wc
(
    FILE *file, int *newlines, int *words
)
{
    int quit = 0;
    unsigned int i = 0;
    int in_word = 0;
    char buffer[LINE_SIZE];

    /* Read in text a line at a time */
    size_t bytes_read = fread(buffer, 1, LINE_SIZE, file);
    do
    {
        /* Reading less than a line means (a) error (b) no more text (EOF)*/
        if ( bytes_read < LINE_SIZE)
        {
            if ( ferror(file) )
            {
                fclose(file);
                fprintf(stderr,"Boom\n");
                exit(-42);
            }

            if ( feof(file) )
            {
                quit = 1;
            }
        }

        /* Iterate over the line of text that was read in */
        for ( i = 0; i < bytes_read; i++)
        {
            /* Count newlines */
            *newlines += buffer[i] == '\n';

            /* Count words. Logic is a little hokey, but it's right. */
            switch( buffer[i] )
            {
            case '\n':  /* Fall through */
            case '\r':  /* Fall through */
            case '\f':  /* Fall through */
            case '\t':  /* Fall through */
            case  ' ':  /* Fall through */
            case '\v':  /* Fall through */
                word_separator:
                if (in_word)
                {
                    in_word = 0;
                    ++(*words);
                }
                break;
            default:
                /* I get this warning here:
                 *    wc2.c:114: warning: subscript has type `char'
                 * on the Sun with -Wall, but I don't get it under
                 * Linux.  Maybe gcc 3.2 has a bug on Solaris (at home
                 * is 3.3.4), or the C libraries are a bit different?
                 * Cuz 'i' is an unsigned int, not a char.  Even
                 * casting or putting in something like '42' won't fix
                 * it.  Totally weird. */
                if ( isspace(buffer[i]) )
                {
                    goto word_separator;
                }
                in_word = 1;
            }
        }

        /* Read next line (even if quit == 1): it's okay. */
        bytes_read = fread(buffer, 1, LINE_SIZE, file);
    } while (!quit);

    return 0;
}

/*!
    The main guts of the program.  Gets the file argument, checks it
    for validity as mandated, and since we're at it, gets # of bytes
    in file from stat information.  Then hands off to wc() subroutine.
*/

int
main
(
    int argc,
    char *argv[]
)
{
    FILE *file;
    int newlines , words, bytes;
    int ret;
    struct stat info;

    newlines = words = bytes = 0;
    --argc;

    if (argc > MAX_FILES)
    {
        fprintf(stderr, "Too many files\n");
        usage();
        exit(ERR_TOO_MANY_FILES);
    }

    /* Err.  Okay, so there's no file.  Print out usage.  Now what?*/
    if ( !argv[1] )
    {
        usage();
        /* Exit here, or wait for error from lstat()? */
    }

    /* Get info about the file: obviously generates error if !argv[1] */
    ret = lstat(argv[1], &info);
    if (ret == -1)
    {
       fprintf(stderr, "%s: no such file or directory\n", argv[1]);
       exit(ERR_FILE_ERR);
    }

    /* Check to see if it's a regular file (not a FIFO, symlink, etc.) */
    if ( !S_ISREG(info.st_mode) )
    {
        fprintf(stderr, "%s: not a regular file\n", argv[1]);
        usage();
        exit(ERR_FILE_ERR);
    }

    /* Open file -- checked for existence, so error here is bad. */
    file = fopen(argv[1], "r" );
    if ( file == NULL )
    {
        fprintf(stderr,"Ouchies\n");
        exit(-42);
    }

    bytes = info.st_size;

    /* Do actual work. */
    wc(file, &newlines, &words);

    /* I don't care if there's a return code: can't do much about it now. */
    (void)fclose(file);

    /* Depending upon system, default appears to be either 5 or 7 here. */
    printf("%7d %7d %7d %s\n", newlines, words, bytes, argv[1]);

    return ERR_OK;
}

