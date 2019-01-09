#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string2.h"

int
main
(
    int argc,
    char *argv[]
)
{
    char *src = "Concatenate me, baby";
    char *dest = (char *)malloc(42);
    memset(dest, 0, 42);
    strcpy(dest,"I am not a monkey");
    int count = 0;


    char **x = split("fuck   one  ");

    if (x == NULL)
    {
        printf("x is NULL\n");
        return 0;
    }

    count = 0;

    while( x && x[count])
    {
        printf("[%3d] is '%s' of length %d\n", count, x[count], strlen(x[count]));
        ++count;
    }

    return 0;
}

