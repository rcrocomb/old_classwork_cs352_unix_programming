/* File: hashtable.h
 *
 * Marshall McMullen, TA provided header file
 * CS352 Summer 2004
 * University of Arizona
 *
 * This header file provides access to all of the types
 * and functions required and supported to implemented
 * a generic hashtable that can accept any type as a
 * key and any type as a value.  Collision resolution is
 * implemented via separate chaining.
 */

/*== COMMON COMPARE, PRINT, and HASH FUNCTIONS ==*/
#include <compare_func.h>
#include <print_func.h>
#include <hashcode_func.h>

/*== DEFINED CONSTANTS ==*/
#define TRUE 1
#define FALSE 0
#define DEFAULT_CAPACITY 100
#define MEM_ERROR -1
#define NULL_HT -2

/*== HELPFUL MACROS TO TEST VALIDITY OF HASHTABLE ==*/
#define memcheck(p) if(!p) do{printf("%s @ %d: Memory allocation failed!\n", __FUNCTION__, __LINE__); exit(MEM_ERROR);}while(0)
#define checktable(ht) do{if(!ht)return NULL_HT;}while(0)
#define checktable_NULL(ht) do{if(!ht)return NULL;}while(0)

/*== TYPES ==*/
typedef struct ht_struct *hashtable;

/* One element or node in the hashtable */
typedef struct hash_node {
    void *key;                  /* unhashed key */
    int key_size;               /* size of key */
    void *value;                /* value */
    int value_size;             /* size of value */
    struct hash_node *next;     /* Pointer to next node */
} hash_node;

/* Struct representing the actual hashtable */
typedef struct ht_struct {
    hash_node **buckets;        /* an array of pointers to buckets */
    int num_buckets;            /* Number of buckets, or indexes into array */
    int num_elements;           /* Number of actual elements inserted == size */
    int (*comp_key) (const void *, const void *);       /* compare keys */
    int (*comp_val) (const void *, const void *);       /* compare values */
    int (*print) (const void *);        /* print function */
    int (*hashcode) (const void *, int table_size);     /* hashcode function */
} ht_struct;

/*== FUNCTION PROTOTYPES ==*/
hashtable ht_init (int (*comp_key) (const void *, const void *),
                   int (*comp_val) (const void *, const void *), int (*print) (const void *),
                   int (*hashcode) (const void *, int));
hashtable ht_init_size (int size, int (*comp_key) (const void *, const void *),
                        int (*comp_val) (const void *, const void *), int (*print) (const void *),
                        int (*hashcode) (const void *, int));
int ht_put (hashtable ht, void *key, int key_size, void *value, int value_size);
void *ht_get (hashtable ht, void *key);
void *ht_remove (hashtable ht, void *key);
void ht_print (hashtable ht);
int ht_contains_value (hashtable ht, void *value);
int ht_contains_key (hashtable ht, void *key);
void ht_clear (hashtable ht);
void ht_destroy (hashtable * ht);
int ht_isempty (hashtable ht);
int ht_size (hashtable ht);
