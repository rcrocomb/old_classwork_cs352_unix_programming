/* File: hashtable_test.c
 *
 * Marshall McMullen, TA provided tester file for hashcode functions
 * CS352 Summer 2004
 * University of Arizona
 *
 * This is a sample tester file to help test all the functions for 
 * the hashtable required for hw5.
 *
 * Please not the use of the "verify" macro.  You pass it some expression
 * that you want to evaluate to true, and if it is not, it will print an 
 * error.  If you run this program with your code and get no output other than
 * an initial listing of the hashtable and a closing statement indiciating tests
 * are done, then your code works perfectly.  If there are any errors, you will
 * get an error message printed to stdout indicating what line number (in this 
 * test file) the error occurred on.
 */

#include <stdio.h>
#include <stdlib.h>
#include <hashtable.h>
#include <string.h>
#include <math.h>

#define num_tests 10
#define verify(exp) do{if(!exp)printf("failure at line %d\n", __LINE__);}while(0)

int main (void)
{
    hashtable tab;
    printf ("===================================================\n");
    printf ("TESTING HASHTABLE\n");
    printf ("===================================================\n");

    tab = ht_init_size (100, compare_string, compare_int, print_s_i, hash_string);

    int nums[num_tests] = { 77, 10, 13, 2, 666, 42, 4321, 1234, 22222, 13214 };
    char *strings[num_tests] =
        { "Hello World", "abcdef", "foobar", "barzoot", "return", "hashtable", "test", "university",
        "negets", "fdecab"
    };

  /*============== TEST PUT && SIZE ===============*/
    printf ("Testing ht_put...\n");
    int i;
    for (i = 0; i < num_tests; i++) {
        printf ("Inserting %s\n", strings[i]);
        ht_put (tab, strings[i], strlen (strings[i]) + 1, &nums[i], sizeof (int));
        verify (ht_size (tab) == i + 1);
        printf ("After insert, hashtable::::\n");
        ht_print (tab);
    }

  /*============== TEST ht_print ===============*/
    printf ("Testing ht_print...\n");
    printf ("Using hashtable: ");
    ht_print (tab);

  /*============== TEST GET ===============*/
    /* Test getting keys that _ARE_ in the hashtable */
    printf ("testing get\n...");
    int val;
    for (i = 0; i < num_tests; i++) {
        val = *(int *) ht_get (tab, strings[i]);

        printf ("Get %s returned %d\n", strings[i], val);

        if (val != nums[i])
            printf ("failure at line %d\n", __LINE__);
    }

  /*============== TEST GET ===============*/
    /* Test getting keys that _ARE_NOT_ in the hashtable */
    /* non-existant key */
    printf ("testing if get fails on non-existent entries...\n");
    verify (ht_get (tab, "asdfzc") == 0);
    verify (ht_get (tab, "somaht") == 0);

  /*============== TEST REMOVE && SIZE ===============*/
    /* test removal of elements that are in the hashtable */
    for (i = 0; i < 3; i++) {
        printf ("Removing %s\n", strings[i]);
        ht_remove (tab, strings[i]);
        verify (ht_get (tab, strings[i]) == 0);
        verify (ht_size (tab) == num_tests - i);

        printf ("After removal, size: %d:\n", ht_size (tab));
        ht_print (tab);
    }

    /* Test remove of elements that are not in the hashtable to ensure it does not crash */
    /* Also make sure size is not modified */
    int size = ht_size (tab);
    printf ("removing stuff not in hashtable\n");
    verify (ht_remove (tab, "NOT HERE") == 0);
    verify (ht_size (tab) == size);
    verify (ht_remove (tab, "QUIT FAILING!") == 0);
    verify (ht_size (tab) == size);
    printf ("Size now: %d\n", ht_size (tab));

  /*============== TEST contains_key ===============*/
    /* Test ht_contains_key on keys that are in the database */
    printf ("Testing contains_key\n");
    printf ("Searching for existing key %s...", strings[3]);
    verify (ht_contains_key (tab, strings[3]) == 1);

    if (ht_contains_key (tab, strings[3]))
        printf ("found!\n");

    printf ("Searching for existing key %s...", strings[4]);
    verify (ht_contains_key (tab, strings[4]) == 1);

    if (ht_contains_key (tab, strings[4]))
        printf ("found!\n");

    /* Test ht_contains_key on keys that NOT are in the database */
    printf ("Searching for two non existin keys ...\n");
    verify (ht_contains_key (tab, "NOT HERE") == 0);
    verify (ht_contains_key (tab, "NOT HERE SO LONG!") == 0);

  /*============== TEST contains_value ===============*/
    /* Test ht_contains_value on values that are in the database */
    printf ("Searching for values in hashtable: '%d' '%d'\n", nums[3], nums[4]);
    verify (ht_contains_value (tab, &nums[3]) == 1);
    verify (ht_contains_value (tab, &nums[4]) == 1);

    /* Test ht_contains_value on values that NOT are in the database */
    printf ("Seraching for values NOT in hashtable: 100 1000\n");
    int z = 100;
    int w = 1000;
    verify (ht_contains_value (tab, &z) == 0);
    verify (ht_contains_value (tab, &w) == 0);

  /*============== TEST CLEAR ===============*/
    printf ("testing clear...\n");
    ht_clear (tab);
    verify (ht_isempty (tab) == 1);
    printf ("Size should now be 0, it is: %d\n", ht_size (tab));
    printf ("is_empty should return 1, it is: %d\n", ht_isempty (tab));

  /*============== TEST DESTROY ===============*/
    printf ("Testing destroy....\n");
    ht_destroy (&tab);

    printf ("Trying to call functions on destroyed hashtable...\n");
    printf ("These should all return NULL_HT (%d)\n", NULL_HT);
    printf ("Any failures will be printed below...\n");

    verify (ht_put (tab, "K", 2, "V", 2) == NULL_HT);
    verify (ht_get (tab, "K") == NULL_HT);
    verify (ht_remove (tab, "K") == NULL_HT);
    verify (ht_contains_value (tab, "K") == NULL_HT);
    verify (ht_contains_key (tab, "K") == NULL_HT);
    verify (ht_isempty (tab) == NULL_HT);
    verify (ht_size (tab) == NULL_HT);
    printf ("Done testing destroy.\n");

    printf ("\n** ALL TESTS COMPLETE **\n\n");

    return 0;
}
