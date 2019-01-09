#include <stdio.h>
#include <unistd.h>             /* getcwd() */
#include <string.h>             /* strlen(), strcpy(), memcpy(), etc.*/
#include <stdlib.h>             /* malloc(), exit(), free() */
#include <limits.h>             /* PATH_MAX */

#define BUFSIZE 50
#define SMART_FREE(a) do { if(a) free(a); a = NULL; } while(0);

#define PATH_ERR -42
#define MALLOC_ERR -17


void
abspath(const char * const in)
{
    char *out = NULL;
    char *temp = NULL;
    const char *travel = NULL;
    const char *trail = NULL;
    int length = 0;
    int length_original = 0;
    int bufsize = BUFSIZE;

    travel = trail = in;

    /* Get current directory */
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

    while ( *trail != '\0')
    {
        if ( (travel[0] == '.') && (travel[1] == '.') && (travel[2] == '/'))
        {
            /* Skip past ../ */
            trail = travel += 3;

            temp = strrchr(out, '/');
            printf("'%s' Got temp as '%s'\n", out, temp);
            if ( temp == NULL)
            {
                strcpy(out, "/");   /* Smallest possible path, so must fit */
            } else
            {
                /* Chop off last element */
                length = temp - out;
                temp = (char *)malloc(length + 1);
                memcpy(temp, out, length);
                temp[length] = '\0';

                SMART_FREE(out);
                out = temp;
            }
        }
        else if ( (travel[0] == '.') && (travel[1] == '/'))
        {
            trail = travel += 2;
        }
        else if ( (travel[0] == '/') || (travel[0] == '\0'))
        {
            printf("Appending\n");

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
            /* Is this always necessary ? */
            temp[length_original] = '/';
            memcpy(temp + length_original + 1, trail, length);
            temp[length + length_original + 1] = '\0';
            SMART_FREE(out);

            out = temp;
            trail = travel;
            printf("%08x %08x Out == '%s'\n", travel, trail, out);
        }
        else
        {
            ++travel;
        }

    }
    printf("%s\n", out);
}

int
main
(
    int argc,
    char *argv[]
)
{
    if ( argv[1] != NULL )
    {
        /*printf("%s\n", argv[1]);*/
        if ( *argv[1] == '/')
        {
        } else
        {
            abspath(argv[1]);
        }
    }

    return 0;
}

