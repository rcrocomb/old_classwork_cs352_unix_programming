#include <string2.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char *abspath (char *path);
static void usage ();

int main (int argc, char **argv)
{

    if (argc != 2)
        usage ();

    char *path = "";

  /*****************************************************************
   * FIXME -- loop over argv and buld up 'path' using strcat2
   *****************************************************************/

    char *full_path = abspath (path);

    printf ("%s\n", full_path);

    return 0;

}

/* Handle all path expansions elegantly */
static char *abspath (char *path)
{
    char *pwd = malloc (FILENAME_MAX * sizeof (char));
    getcwd (pwd, FILENAME_MAX);
    char *full_path = "";

    /* Check if it is already an absolute path */
    if (*path == '/')
        return path;

    /* store pwd in prefix */
    char *prefix = pwd;

    /*****************************************************************
     * FIXME -- write the rest of the code for abspath 
     *****************************************************************/

    /*****************************************************************
     * NO NEED TO CHANGE ANYTHING BELOW HERE....
     *****************************************************************/
    /* FINAL POST CONDITION: Path must have a '/' at beginning */
    if (*full_path != '/') {
        printf ("first char now: %c\n", *full_path);
        printf ("Error parsing pathname: %s I GOT IT TO ==> %s\n", path, full_path);
        exit (1);
    }

    /* We're done with pwd */
    free (pwd);

    return full_path;
}

static void usage ()
{
    printf ("Usage: abspath [PATH]\n");
    exit (1);
}
