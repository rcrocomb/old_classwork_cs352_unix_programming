#include "arraylist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    char buf[128];
    int i;
    char *s = NULL;
    int con = 0;
    char *a = NULL;
    char *b = NULL;
    int x = 0;


    /* Create */
    arraylist list = al_init (compare_string, print_s);

    printf ("al_size: %d size: %d\n", al_size (list), list->size);

    /* 10 adds */
    for (i = 0; i < 10; i++) {
        sprintf (buf, "Message #%d", i);
        al_add (list, buf, strlen (buf) + 1);
    }

    al_add_at (list, 3, "NANO", strlen ("NANO") + 1);
    al_add_at (list, 0, "0th", strlen ("0th") + 1);
    al_add_at (list, list->size, "last", strlen ("last") + 1);


    printf ("About to printlist\n");
    al_printlist (list);
    printf ("al_size: %d size: %d\n", al_size (list), list->size);

    printf ("--Testing remove of NANO--\n");
    al_remove (list, "NANO");
    printf("Remove succeeded\n"); fflush(stdout);
    al_printlist (list); fflush(stdout);

    printf ("--TESTING REMOVEALL(NANO)--\n");
    fflush(stdout);
    al_printlist (list);
    al_add_at (list, 0, "NANO", strlen ("NANO") + 1);
    al_add (list, "NANO", strlen ("NANO") + 1);
    al_add (list, "NANO", strlen ("NANO") + 1);
    al_add (list, "NANO", strlen ("NANO") + 1);
    al_add (list, "NANO", strlen ("NANO") + 1);
    al_printlist (list);
    printf("Calling remove all\n");
    fflush(stdout);
    al_remove_all (list, "NANO");
    printf("Remove all complete\n");
    fflush(stdout);
    al_printlist (list);

    s = al_remove_at (list, 1);
    s = al_remove_at (list, 7);
    al_printlist (list);

    printf ("\nremove_at returned: '%s'\n", s);

    al_clear (list);
    al_printlist (list);

    al_add (list, "Test #1", strlen ("Test #1") + 1);
    al_add (list, "Test #2", strlen ("Test #2") + 1);
    al_add (list, "Test #3", strlen ("Test #3") + 1);
    al_add (list, "Test #4", strlen ("Test #4") + 1);

    con = al_contains (list, "Test #1");
    printf ("Contains? (YES!): %d\n", con);
    printf ("Contains? (NO!): %d\n", al_contains (list, "FOO"));

    a = al_get (list, 0);

    printf ("al_get: %s\n", a);


    al_clear (list);
    printf ("Empty? %d\n", al_isempty (list));

    al_printlist (list);

    al_add (list, "Test #1", strlen ("Test #1") + 1);
    al_printlist (list);

    al_add (list, "Test #2", strlen ("Test #2") + 1);
    al_add (list, "Test #3", strlen ("Test #3") + 1);
    al_add (list, "Test #4", strlen ("Test #4") + 1);
    al_printlist (list);
    printf ("index of 'Test #2':%d\n", al_indexof (list, "Test #2"));
    b = al_set (list, 2, "WOW", strlen ("WOW") + 1);
    printf ("b = %s\n", b);
    al_printlist (list);
    printf ("Empty? %d\n", al_isempty (list));

    printf ("old cap: %d\n", list->capacity);
    al_trim (list);
    printf ("new cap: %d\n", list->capacity);

    printf("Print list\n");
    fflush(stdout);
    al_printlist (list);
    printf("al_remove_range\n");
    fflush(stdout);
    al_remove_range (list, 2, 3);
    printf("print list again\n");
    fflush(stdout);
    al_printlist (list);
    printf("more remove range\n");
    fflush(stdout);

    al_remove_range (list, 3, 2);

    printf("Finish more remove_range\n");
    fflush(stdout);

    al_printlist (list);

    printf("al_destroy\n");
    fflush(stdout);

    al_destroy(&list);

    printf("finished al_desstory \n");
    fflush(stdout);


    /* Test functions POST destory -- all should return NULL_LIST */
    x = al_add(list, "T", strlen("T") + 1);

    if(x != NULL_LIST)
      printf("\n\nFAILURE!\n\n");

    fflush(stdout);

    return 0;
}
