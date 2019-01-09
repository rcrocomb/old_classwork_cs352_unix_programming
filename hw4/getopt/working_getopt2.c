#include <stdlib.h>         /* exit() */
#include <string.h>         /* strchar() */
#include <stdio.h>          /* printf() */

int optind2;
int opterr2 = 1;
int optopt2;
int c_offset;

char *nonopt;

#define NONOPTION -2

void
error(const int errcode)
{
    if (!opterr2)
    {
        return;
    }

    switch(errcode)
    {
        case EOF:
            fprintf(stderr, "End of file.\n");
            break;
        case NONOPTION:
            fprintf(stderr, "Invalid option character found.\n");
            break;
    }
}

int
getopt2(int argc, char *argv[], const char *optstring)
{
    static char *pos = NULL;
    char result;
    char **save = argv;
    int i;

    printf("\nRunning: %d\n", optind2);

    /* Do not search executable name */
    --argc;
    if ( (argc <= 0) || (argv == NULL) || (optstring == NULL) || (optind2 == argc))
    {
        printf("Returning EOF\n");
        printf("argc == %d\n", argc);
        printf("argv == %08x \n", argv);
        printf("optstring == '%s'\n", optstring);
        printf("optind2 == %d\n", optind2);
        return EOF;
    }

    ++argv;

    printf("\n");
    for( i = 0; i < argc; i++)
    {
        printf("[%3d] == '%s'\n", i, argv[i]);
    }

    argv += optind2;
    /* Search array of strings */

    printf("argv == %08x: '%s'\n", argv, *argv);

    nonopt = NULL;
    while (*argv != NULL)
    {
        if ( !pos || (pos && (*pos == '\0')) )
        {
            pos = *argv;
            printf("Assigning pos to '%s'\n", pos);
        }

        /* Find strings that are valid and begin with '-' */
        if( **argv == '-')
        {
            /* Skip over '-' */
            //if (== 0)
            if (*pos == '-')
            {
                printf("Skipping '-' : bumping pos '%s' :", pos);
                ++pos;
                printf("'%s'\n", pos);
            }

            printf("Checking string '%s'\n", pos);

            /* Look for option character. */
            for ( i = 0; (i < strlen(optstring)) && (*pos != optstring[i]); ++i)
            {
                printf("Checking '%c' against '%c' of '%s': No\n",
                       optstring[i], *pos, pos);
            }

            /* Whether found or not, go to next char */
            printf("Bumping pos '%s' : ", pos);
            ++pos;

            /* Did not find any option characters, but yet had '-' */
            if (i == strlen(optstring))
            {
                printf("'%s' : %08x '%s'\n",
                       pos, pos,((*pos == NULL) ? "YES" : "No"));
                /* XXX: no! Don't just skip this char: skip entire string? */
                printf("Found invalid option character\n");
                error(EOF);
                printf("Optind == %d : '%s'\n", optind2, *argv);
                optopt2 = *(pos-1);
                if ( *pos == '\0')
                {
                    ++argv;
                }
                result = '?';
                break;
            }

                printf("'%s' : %08x '%s'\n",
                       pos, pos,((*pos == NULL) ? "YES" : "No"));
                printf("Successfully checked'%c' against '%c' of '%s' -- now '%s''\n",
                       optstring[i], *(pos-1), pos-1, pos);
                result = *(pos - 1);
                if ( *pos == '\0')
                {
                    ++argv;
                }
                break;
        } else if (pos != NULL)
        {
            printf("No '-' in %s\n",pos);
            nonopt = pos;
            pos = NULL;
            ++argv;
            break;
        }

        /* Done all the checking for this string, move to next */
        //++argv;
    }

    optind2 = argv - save - 1;
    printf("optind == %d\npos == '%s'\nDone while\n", optind2 , pos);

    /* Found a string that began with '-', but the argument wasn't a valid
     * option character. */
    if (nonopt != NULL)
    {
        printf("Got non-option : '%s'\n",nonopt);
        return NONOPTION;
    }

    if ( pos == NULL)
    {
        return EOF;
    }

    if ( result == '?')
    {
        // XXX: can't do this.
        //pos = NULL;
        return result;
    }

    printf("Found an option character as '%c'\n", *(pos -1));

    /* Success.  Return the option character that we found. */

    return result;
}

int
main
(
    int argc,
    char *argv[]
)
{
    int result = 0;
    const char *optstring = "cabdefghmijkl";

    printf("Optind2 == %d\n", optind2);

    int i = 0;

    for( ; i < argc; ++i)
    {
        printf("[%3d] == '%s'\n", i, argv[i]);
    }

    while ( (result = getopt2(argc, argv, optstring)) != 42)
    {
        switch(result)
        {
            case '?':
                printf("Got error char as '%c'\n", optopt2);
                break;

            case NONOPTION:
                printf("Get non-option string as '%s'\n", nonopt);
                break;

            case EOF:
                printf("End of File\n");
                goto out;

            default:
                printf("Successful Result == %c\n", result);
        }
    }
out:
    printf("Done\n");

    return 0;
}

