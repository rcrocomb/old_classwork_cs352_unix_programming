#include <unistd.h>
#include <stdio.h>


int
main
(
    int argc,
    char *argv[]
)
{
    char buffer[1024];
    if ( getcwd(buffer, 1024))
    {
        printf("path is '%s'\n", buffer);
    } else
    {
        printf("getcwd failed\n");
    }

    return 0;

}
