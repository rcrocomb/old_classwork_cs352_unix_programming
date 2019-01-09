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
    int i;
    for (i = 0; i < num_tests; i++) {
        ht_put (tab, strings[i], strlen (strings[i]) + 1, &nums[i], sizeof (int));
        verify (ht_size (tab) == i + 1);
    }

  /*============== TEST ht_print ===============*/
    printf ("Using hashtable: ");
    ht_print (tab);

  /*============== TEST GET ===============*/
    /* Test getting keys that _ARE_ in the hashtable */
    int val;
    for (i = 0; i < num_tests; i++) {
        val = *(int *) ht_get (tab, strings[i]);

        if (val != nums[i])
            printf ("failure at line %d\n", __LINE__);
    }

  /*============== TEST GET ===============*/
    /* Test getting keys that _ARE_NOT_ in the hashtable */
    /* non-existant key */
    verify (ht_get (tab, "asdfzc") == 0);

    /* non-existant key, but has the same hash code as an existant key */
    verify (ht_get (tab, "somaht") == 0);

  /*============== TEST REMOVE && SIZE ===============*/
    /* test removal of elements that are in the hashtable */
    for (i = 0; i < 3; i++) {
        ht_remove (tab, strings[i]);
        verify (ht_get (tab, strings[i]) == 0);
        verify (ht_size (tab) == num_tests - i);
    }

    /* Test remove of elements that are not in the hashtable to ensure it does not crash */
    /* Also make sure size is not modified */
    int size = ht_size (tab);
    verify (ht_remove (tab, "NOT HERE") == 0);
    verify (ht_size (tab) == size);
    verify (ht_remove (tab, "QUIT FAILING!") == 0);
    verify (ht_size (tab) == size);

  /*============== TEST contains_key ===============*/
    /* Test ht_contains_key on keys that are in the database */
    verify (ht_contains_key (tab, strings[3]) == 1);
    verify (ht_contains_key (tab, strings[4]) == 1);

    /* Test ht_contains_key on keys that NOT are in the database */
    verify (ht_contains_key (tab, "NOT HERE") == 0);
    verify (ht_contains_key (tab, "NOT HERE") == 0);

  /*============== TEST contains_value ===============*/
    /* Test ht_contains_value on values that are in the database */
    verify (ht_contains_value (tab, &nums[3]) == 1);
    verify (ht_contains_value (tab, &nums[4]) == 1);

    /* Test ht_contains_value on values that NOT are in the database */
    int z = -10;
    int w = -1000;
    verify (ht_contains_value (tab, &z) == 0);
    verify (ht_contains_value (tab, &w) == 0);

  /*============== TEST CLEAR ===============*/
    ht_clear (tab);
    verify (ht_isempty (tab) == 1);

  /*============== TEST DESTROY ===============*/
    ht_destroy (&tab);
    verify (ht_put (tab, "K", 2, &z, sizeof (int)) == NULL_HT);
    verify (ht_get (tab, "K") == NULL_HT);
    verify (ht_remove (tab, "K") == NULL_HT);
    verify (ht_contains_value (tab, &z) == NULL_HT);
    verify (ht_contains_key (tab, "K") == NULL_HT);
    verify (ht_isempty (tab) == NULL_HT);
    verify (ht_size (tab) == NULL_HT);

    printf ("\n** ALL TESTS COMPLETE **\n\n");

    return 0;
}
