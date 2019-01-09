/* File: hashtable_skel.c
 *
 * Marshall McMullen, TA provided skelaton file
 * for hashtable program for HW5
 * CS352 Summer 2004
 * University of Arizona
 *
 * This is a skelaton file to help get you started
 * on writting your hashtable using Separate 
 * Chaining (linked lists) for collision resolution.
 *
 * You may modify anything you like in this code,
 * as well as any of the provided header files,
 * providing you do not alter any of the defined
 * constants or return values.
 */

/*===============================================
 * INCLUDE FILES
 *===============================================*/
#include <stdlib.h>
#include <stdio.h>
#include <hashtable.h>
#include <string.h>

/*===============================================
 * ht_init_size -- initialize a hashtable with a
 * specified minimum size.
 *===============================================*/
hashtable ht_init_size (int size, int (*comp_key) (const void *, const void *),
                        int (*comp_val) (const void *, const void *), int (*print) (const void *),
                        int (*hashcode) (const void *, int))
{
    int i;

    /* Malloc space on heap for a new hashtable */
    hashtable table = (hashtable) malloc (sizeof (struct ht_struct));
    memcheck (table);

    /* Use 'size' as a minimum value -- for optimization sake, use the next prime number after
     * 'size' as the actual size */
    size = nextPrime (size);

    /* Malloc space on heap for this hashtable's array (separate chains) */
    table->buckets = malloc (sizeof (*(table->buckets)) * size);
    memcheck (table->buckets);

  /** FIXME: Initialize all fields in hashtable **/

  /** FIXME: initialize the elements in the table->buckets array **/

    return table;
}

hashtable ht_init (int (*comp_key) (const void *, const void *),
                   int (*comp_val) (const void *, const void *), int (*print) (const void *),
                   int (*hashcode) (const void *, int))
{
    return ht_init_size (DEFAULT_CAPACITY, comp_key, comp_val, print, hashcode);
}

int ht_put (hashtable ht, void *key, int key_size, void *value, int value_size)
{
    /* Make sure table is a valid pointer */
    checktable (ht);

    /* Get the hashcode for the specified key */
    size_t ind = ht->hashcode (key, ht->num_buckets);

  /** FIXME: Copy the key and values into new pointers **/

  /** FIXME: malloc off a new node to be inserted **/

  /** FIXME: copy the new key and values into the new node **/

  /** FIXME: Don't forget to use memcheck to ensure all malloc's succeeded!! **/

  /** FIXME: all memory handling done, now put the key-value pair into the table **/

  /** FIXME: Add new element to the ==> front <== of the list **/

    return 0;
}

/*===============================================
 * ht_get:  Gets data stored at a specific key, if that key is in the hashtable, otherwise
 * returns null.
 *===============================================*/
void *ht_get (hashtable ht, void *key)
{
    /* Make sure table is a valid pointer */
    checktable_NULL (ht);

    /* Get the index the key would hash to */
    int index = ht->hashcode (key, ht->num_buckets);

  /** FIXME: If there are no elements in this bucket, Return NULL **/

  /** FIXME: Otherwise, search the linked list starting at bucket[index]
      and look for the specified key.  Remember, to compare to keys, you should 
      make a call such as (ht->comp_key(key, tmp->key) == 0) to see if
      to keys are equal!! **/

    /* No match was found if we get here, return NULL! */
    return NULL;
}

void *ht_remove (hashtable ht, void *key)
{
    /* Make sure table is a valid pointer -- if not, return NULL */
    checktable_NULL (ht);

    /* Get the key this would hash to */
    size_t ind = ht->hashcode (key, ht->num_buckets);

    /* Use two nodes to iterate through the hashtable */
    hash_node *elem = ht->buckets[ind];
    hash_node *prev;

  /** FIXME: if elem == NULL, there is no element with that key, return NULL **/

  /** FIXME: Otherwise, search through the nodes in the linked list starting at
      elem and using the comp_key function over and over to look for a matching
      entry with that key.  If it is found, you should perform the following:

      1. free the key at that node
      2. free the node itself
      3. Decrement ht->num_elements
      4. RETURN THE NODE THAT WAS JUST REMOVED!
  **/

    /* IF we get here, no element with the given key, so return NULL */
    return NULL;
}

/*==============================================================================
 * Function: list_print()
 * Purpose: The purpose of this function is to print the contents of
 *	    the hashtable in a format similar to java's hashtable toString
 *==============================================================================*/
void ht_print (hashtable table)
{
    /* Make sure the pointer is valid! */
    if (!table) {
        printf ("Not a valid hashtable!\n");
        return;
    }

  /** FIXME: Iterate through all nodes in the hashtable, starting at 
      table->buckets[0] up through table->buckets[num_buckets], and on
      each iteration, print that node using ht->print function.  NOTE:
      You should _NOT_ print a NULL value in the hashtable.  Ensure the
      output of this function matches the provided solution!
  **/
}

/* Generic contains method to check for existence of void * value */
int ht_contains_value (hashtable table, void *value)
{
    /* Make sure the table is a valid pointer */
    checktable (table);

  /** FIXME: Itereate throug the hashtable's buckets and use the 
      hashtable's comp_val function to see if the requested value
      is in the hashtable.  If it is, return TRUE, else return FALSE.
  **/

    /* If we get here, it was not found, return FALSE */
    return FALSE;
}

int ht_size (hashtable ht)
{
    /* Make sure the table is a valid pointer */
    checktable (ht);

  /** FIXME: Return the number of elements in the hashtable **/
    return -1;                  // <==== MUST CHANGE THIS! THIS IS A PLACEHOLDER SO IT
    // WILL COMPILE!
}

int ht_isempty (hashtable ht)
{
    /* Make sure the table is a valid pointer */
    checktable (ht);

  /** FIXME: return TRUE if the table is empty (num_elements == 0)
      else return FALSE
  **/
    return -1;                  // <==== MUST CHANGE THIS! THIS IS A PLACEHOLDER SO IT
    // WILL COMPILE!
}

/* Specific helper method to see if a particular key is in the hashtable or not */
int ht_contains_key (hashtable table, void *key)
{
    /* Make sure the table is a valid pointer */
    checktable (table);

  /** FIXME: IF key == NULL, return FALSE
      else, search the hashtable and look for the specified key.  
      If the key is found (using comp_key), then return TRUE,
      else return FALSE. Don't re-invent the wheel, you have another
      function you have written that will do all this for you ;)
  **/

  /** PLACEHOLDER ONLY... CHANGE AS NEEDED... */
    return FALSE;
}

/*
 * This function provides ability to free all the memory previously
 * occupied by a hashtable when we're done with it. 
 */
void ht_clear (hashtable table)
{
    /* If the table's already been cleared, just return, nothing to do! */
    if (!table)
        return;

    int i;

  /** FIXME: Iterate over the hashtable and perform the following 
      on each node:
      
      1.  free the key in that node
      2.  free the value in that node

      Also, at the end of this process, the num_elements should
      equal 0.
  **/
}

void ht_destroy (hashtable * table)
{
    /* If table is not a valid pointer, there's nothing to do, return */
    if (!*table)
        return;

    /* Clear the hashtable */
    ht_clear (*table);

  /** FIXME: NOW, you must free the hashtable itself -- and, since
      we want subsequent calls on this hashtable to fail (since it has
      been 'destroyed'), you MUST ensure that table is NULL.  Recall, 
      'free' does ==>NOT<== set pointers to NULL, it only marks them
      as available for future use.  Thus, you must explicitly set pointer
      to NULL.  This is why you need the address of table, and not just table
      due to C's pass by value semantics.
  **/
}

/* PROVIDED function -- Static helper function to check if a given int is prime or not */
static int isPrime (int n)
{
    int i;

    if (n == 2 || n == 3)
        return 1;

    if (n == 1 || n % 2 == 0)
        return 1;

    for (i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;

    return 1;
}

/* PROVIDED function -- Static helper function to find the next prim number after a given seed */
static int nextPrime (int n)
{
    if (n % 2 == 0)
        n++;

    while (!isPrime (n))
        n += 2;

    return n;
}
