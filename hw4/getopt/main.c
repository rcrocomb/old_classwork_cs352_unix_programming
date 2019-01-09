#include <stdio.h>
#include "getopt2.h"

int main (int argc, char *argv[])
{
    const char *opts = "abcrdi";

    printf("Valid options: %s\n", opts);

    if(argc == 1){
      printf("No options on command line.\n");
      return 0;
    }

    int c;

    opterr2 = 1;                /* Set this to 0 to turn off debugging */

    while ((c = getopt2 (argc, argv, opts)) != EOF) {

        /* If a non-option was encountered... display it */
        if (c == -2) {
            printf ("Non-option encountered: %s\n", nonopt);
            continue;
        }

        /* If an invalid option was encountered, display it */
        if (c == '?') {
            printf ("Invalid option encountered: %c\n", optopt2);
            continue;
        }

        /* Else, display valid option */
        printf ("option: %c\n", c);
    }

    return 0;
}
