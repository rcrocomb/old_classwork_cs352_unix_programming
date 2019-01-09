#include <stdio.h>
#include <stdlib.h>         // drand48()


int
main
(
    int argc,
    char *argv[]
)
{
    const double ITERATIONS = argv[1] ? atof(argv[1]) : 10;

    const long SEED = 42;
    const unsigned int STRING_LENGTH = 40;


    unsigned int i;
    unsigned int j;
    double result;

    srand48( SEED );
    for (i = 0; i < ITERATIONS; i++)
    {
        for (j = 0; j < STRING_LENGTH; j++)
        {
            result = drand48();
            char c = result * (double)('z' - 'a') + (double)'a';
            printf("%c",c);
        }
        printf("\n");
    }

    return 0;
}

