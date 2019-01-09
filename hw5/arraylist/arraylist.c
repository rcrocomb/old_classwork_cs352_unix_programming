#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "arraylist.h"

/******************************************************************************/
/* Author: Robert Crocombe                                                    */
/* Class: CS352 Summer 04                                                     */
/* Assignment: HW5                                                            */
/*                                                                            */
/* Implementation of a Java Arraylist-like data structure that can be a       */
/* container for any type of data that can provide a minimal number of        */
/* support routines: at a minimum, a function for comparison two values       */
/* and a function for printing out the values as well.                        */
/******************************************************************************/

/******************************************************************************/
/* Macros                                                                     */
/******************************************************************************/

#define checksize(list) do                                                  \
                        {                                                   \
                            if((list)->size == (list)->capacity)grow(list); \
                        } while(0)

#define checklist(list) do                                                  \
                        {                                                   \
                            if(!(list)) return NULL_LIST;                   \
                        } while(0)

#define check(err)  do                                                      \
                    {                                                       \
                        if((err) != OK)                                     \
                            return (err);                                   \
                    } while(0)

#define checkindex(list, i) do                                              \
                            {                                               \
                                if((i)< 0 || (i) > (list)->size)return BOUNDS;\
                            } while(0)

#define check_list_index(list, i) do                                        \
                                  {                                         \
                                    checklist(list); checkindex(list, i);   \
                                  } while(0)                                \

#define check_list_index_NULL(list, i) do                                   \
                                       {                                    \
                                        if(   !(list)                       \
                                           || ((i) < 0 || (i) > (list)->size))\
                                            return NULL;                    \
                                       } while(0)

#define SMART_FREE(a)   do                                                  \
                        {                                                   \
                            if((a))                                         \
                                free((a));                                  \
                            (a) = NULL;                                     \
                        } while(0)

/******************************************************************************/
/* Types                                                                      */
/******************************************************************************/

typedef  int (*al_compare_func)(const void *, const void *);
typedef  void (*al_print_func)(const void *);


/******************************************************************************/
/* Internal Prototypes                                                        */
/******************************************************************************/

static int shift (arraylist list, int index);
static int remove_hole (arraylist list, int);
static int grow (arraylist list);
static node *make_node (void *data, int size);
static int free_node (arraylist list, int index);
static void *getdata (arraylist list, int index);
static int getdata_size (arraylist list, int index);
static node *getnode (arraylist list, int index);

/******************************************************************************/
/* Internal Definitions                                                       */
/******************************************************************************/

/*!
    Given a valid arraylist 'list' and a valid index 'index', shifts all
    elements to the right of (and including) index one additional position
    to the right, i.e. index->(index + 1), etc.

    Returns

    NULL_LIST if the list is invalid
    BOUNDS if the index is out of range
    TRUE on success
*/

int
shift(arraylist list, int index)
{
    unsigned int i = 0;

    /* Ensure the list indexes are valid */
    check_list_index (list, index);

    /* Cannot shift -- list is full: make bigger list */
    if ( list->capacity == list->size )
    {
        (void)grow(list); /* cheating: grow only returns TRUE */
    }

    /* There's room to shift now, one way or the other */
    for ( i = list->size; i > index; --i)
    {
        list->array[i] = list->array[i - 1];
    }

    /* We're done, return */
    return TRUE;
}

/*!
    Given a valid arraylist 'list' and a valid index 'index' that points
    to a spot in the list that is to be considered a hole, shifts all data
    elements to the right of the hole left to fill the hole.

    If the hole isn't a hole, this routine _makes_ it one.

    Returns:
    NULL_LIST if 'list' is NULL
    BOUNDS if 'index' is out of range
    TRUE on success
*/

int
remove_hole (arraylist list, int index)
{
    unsigned int i = 0;
    /* Ensure the list indexes are valid */
    check_list_index (list, index);

    printf("remove hole\n");
    fflush(stdout);

    if (!list->array)
    {
        return ERR;
    }

    if (list->array[index])
    {
        printf("SHOULD NEVER HIT THIS NO MORE?\n");
        /* There's something in our hole! Stomp it: free_node() leaves this. */
        (void)free_node (list, index);
        printf("Setting index @ %d to NULL\n", index);
        list->array[index] = NULL;
    }

    printf("Shrinking hole\n");

    for (i= 0; i < list->size; ++i)
    {
        printf("[%4d] == %08x '\n", i, list->array[i]);
    }

    /* no memcpy because of overlapping range */
    memmove(list->array + index,
            list->array + index + 1,
            (list->capacity - index - 1) * sizeof(node *));
    --list->size;

    printf("\n");
    for (i= 0; i < list->size; ++i)
    {
        printf("[%4d] == %08x\n", i, list->array[i]);
    }

    return TRUE;
}

/*!
    Increase list of valid list 'list' by GROW_FACTOR: this requires
    allocating a new array and copying the pointers from the old to the new.

    returns NULL_LIST if 'list' is NULL, else returns TRUE
*/

int
grow (arraylist list)
{
    const int new_capacity = GROW_FACTOR * list->size;
    node **new_array;

    /* Ensure the list indexes are valid */
    checklist (list);

    new_array = (node **)malloc(new_capacity * sizeof(node *));
    memcheck(new_array);

    /* Copy pointers from old array to new array*/
    memcpy(new_array, list->array, list->size * sizeof(node *));

    /* Get rid of old array, point list array to new array*/
    SMART_FREE(list->array);
    list->array = new_array;

    /* Set capacity to reflect new storage ability */
    list->capacity = new_capacity;

    return TRUE;
}

/*!
    Given data pointed to by 'data' which is of size 'size', creates a new
    node for the arraylist and returns it.  The node has a copy of the data
    in 'data': it does not simply alias it.

    Returns a pointer to the new node.
*/

node *
make_node (void *data, int size)
{
    node *n = NULL;

    printf("\nNode size == %d\n", sizeof(node));

    printf("----------------------BEGINNING-----------------------------\n");
    printf("%20s %8s %8s %4s: %s\n", "comment","n add", "data add","sz", "string");

    printf("%20s %08x %08x %4d: '%s'\n", "beginning", n, data, size, (char *)data);
    fflush(stdout);

    /* Malloc off space for a node */
    n = (node *) malloc (sizeof (node));

    /* Make sure malloc succeeded */
    memcheck (n);

    //printf("%20s %08x %08x %4d: '%s'\n", "mallocd n", n, data, size, (char *)data);
    printf("%20s %08x %08x %4d: '%s' : %08x\n",
           "mallocd n", n, data, size, (char *)data, n->data);

    fflush(stdout);

    /* ALSO! Must malloc off space for the DATA!! */
    //n->data = (void *)malloc (sizeof(char) * size);
    n->data = malloc (8192);

    printf("%20s %08x %08x %4d: '%s' : %08x %08x (%4d): '%s'\n",
           "mallocd data", n, data, size, (char *)data, n->data, n->data_size, n->data_size, (char *)n->data);
    fflush(stdout);

    memcheck (n->data);
    memcpy (n->data, data, size);

    printf("%20s %08x %08x %4d: '%s' : %08x %08x (%4d): '%s'\n",
           "memcpy data", n, data, size, (char *)data, n->data, n->data_size, n->data_size, (char *)n->data);
    fflush(stdout);

    n->data_size = size;

       printf("%20s %08x %08x %4d: '%s' : %08x %08x (%4d): '%s'\n",
           "set size", n, data, size, (char *)data, n->data, n->data_size, n->data_size, (char *)n->data);

    printf("---------------------------END------------------------------\n");
    fflush(stdout);

    return n;
}

/*!
    Given a valid arraylist 'list' and a valid index into the list, 'index',
    deletes the data and the node at that index within the arraylist.

    Returns:

    NULL_LIST if the list is invalid
    BOUNDS if the index is out of range
    TRUE if the node was successfully freed
*/

int
free_node (arraylist list, int index)
{
    node *n = NULL;
    check_list_index (list, index);

    printf("Freenode for %08x and %d\n", list, index);
    fflush(stdout);

    n = getnode (list, index);

    printf("Got node at %08x\n", n);
    fflush(stdout);

    if (n)
    {
        SMART_FREE(n->data);
    }

    printf("SMART_FREE on n->data\n");
    fflush(stdout);

    SMART_FREE(n);
    list->array[index] = NULL;

    printf("SMART_FREE on n\n");
    fflush(stdout);

    printf("End free node\n");
    fflush(stdout);

    return TRUE;
}

/*!
    Given a valid list and index, returns a pointer to the data in the array
    at node 'index', i.e. the element is modifiable.
*/

void *
getdata (arraylist list, int index)
{
    node *n = NULL;

    /* Check to ensure all parameters are valid! */
    check_list_index_NULL(list, index);

    /* Get the node at the required index */
    n = getnode (list, index);

    /* If it is null, return NULL */
    if (!n)
    {
        return NULL;
    }

    /* GET the data stored in the node */
    return n->data;
}

/*!
    Given a valid list and index, returns the size of the element at index.
*/

int
getdata_size (arraylist list, int index)
{
    node *n = NULL;

    /* Ensure indexes are valid */
    check_list_index (list, index);

    /** Get a node from the list && index using
        getnode function. This example should be
        used to help you anywhere else in your code
        where you want to convert an index in the arraylist
        into a node.
  **/
    n = getnode (list, index);

    /* If the node is NULL, just return 0 */
    if (!n)
    {
        return 0;
    }

    /* Return the size stored in that node */
    return n->data_size;
}

/*!
    Given a valid list and index, returns a pointer to the node at 'index'.

    Returns

    NULL is the list is invalid or index is out of bounds
*/

node *
getnode (arraylist list, int index)
{
    check_list_index_NULL(list, index);

    return list->array[index];
}


/******************************************************************************/
/* Definitions                                                                */
/******************************************************************************/

arraylist
al_init
(
    al_compare_func compare,
    al_print_func print
)
{
    return al_init_size(DEFAULT_CAPACITY, compare, print);
}

arraylist
al_init_size
(
    int capacity,
    al_compare_func compare,
    al_print_func print
)
{
    arraylist list = (arraylist)malloc(sizeof(al));
    memcheck(list);

    list->size = 0;
    list->comp = compare;
    list->print = print;

    list->capacity = capacity;
    list->array = (node **)malloc(capacity * sizeof(node *));
    memcheck(list->array);

    return list;
}

int
al_add_at
(
    arraylist list,
    int index,
    void *data,
    int size
)
{
    /* Ensure the list indexes are valid */
    check_list_index (list, index);

    if (shift(list, index) != TRUE)
    {
        return FALSE;
    }

    list->array[index] = make_node(data, size);
    if ( !(list->array[index]) )
    {
        return FALSE;
    }

    ++list->size;

    return TRUE;
}

int
al_add
(
    arraylist list,
    void *data,
    int size
)
{
    /* Ouchies for when invalid list: fixed. */
    return al_add_at(list, (list ? list->size : 0), data, size);
}


int
al_remove
(
    arraylist list,
    void *data
)
{
    int ret = FALSE;
    node *n = NULL;
    unsigned int i = 0;

    checklist(list);

    if (!list->array)
    {
        return ERR;
    }

    for( i = 0; i < list->size; ++i)
    {
        n = list->array[i];
        if ( n && (list->comp( n->data, data) == 0) )
        {
            printf("Match @ %4d: '%s'\n", i,(char *)n->data); fflush(stdout);
            ret =   free_node(list, i) && remove_hole(list, i);
            /* pedantic */
            ret = ret ? TRUE : FALSE;
            break;
        }
    }

    return ret;
}

int
al_remove_all
(
    arraylist list,
    void *data
)
{
    int ret = FALSE;
    checklist(list);

    while( (ret = al_remove(list, data)) ); /* Teeny-tiny loop */
    return ret ? TRUE : FALSE;
}

void *
al_remove_at
(
    arraylist list,
    int index
)
{
    void * copy = NULL;
    void * data = NULL;
    int data_size = getdata_size(list, index);
    check_list_index_NULL(list, index);

    data = getdata(list, index);                    /* get pointer to data */
    if (data)
    {
        copy = (char *)malloc( data_size );
        memcheck(copy);
        memcpy(copy, data, data_size);
        (void)free_node(list, index);               /* remove original */
        remove_hole(list, index);
    }
    return data;
}

int
al_remove_range
(
    arraylist list,
    int begin,
    int end
)
{
    int i = begin;
    int ret = TRUE;

    check_list_index(list, begin);
    checkindex(list, end);

    if ( end < begin )
    {
        printf("Canna dooit, keptin\n");
        fflush(stdout);
        return BOUNDS;
    }

    for ( ; (i < end) && ret; ++i)
    {
        ret = ret && al_remove_at(list,i);
    }
    return ret ? TRUE : FALSE;
}

/*!
    Returns OK, not TRUE, so must perform swap-a-roo on return codes.
*/

int
al_clear
(
    arraylist list
)
{
    return al_remove_range(list, 0, list->size) ? OK : ERR;
}

/*!
    Returns true if the list contains data as stored at 'data'.  Elements are
    compared using arraylist's compare routine.  Returns false if arraylist
    does not contain 'data'.
*/

int
al_contains
(
    arraylist list,
    void *data
)
{
    int ret = FALSE;
    unsigned int i = 0;

    checklist(list);

    if ( data )
    {
        for ( ; (i < list->size) && !ret; ++i)
        {
            if ( list->comp( (list->array[i])->data, data) == 0)
            {
                ret = TRUE;
            }
        }
    }
    return ret;
}

int
al_ensure_capacity
(
    arraylist list,
    int capacity
)
{
    int ret = TRUE;
    checklist(list);

    while ( (list->capacity < capacity) && ret)
    {
        ret = grow(list);
    }
    return ret ? OK : ERR;
}

void *
al_get
(
    arraylist list,
    int index
)
{
    check_list_index_NULL(list, index);

    return getdata(list, index);
}

int
al_indexof
(
    arraylist list,
    void *data
)
{
    unsigned int i = 0;

    checklist(list);

    /* duplicate assignment to remove warning: stupid gcc */
    for ( i = 0 ; i < list->size; ++i)
    {
        if ( list->comp((list->array[i])->data, data) == 0)
        {
            break;
        }
    }

    /* if i == list->size, then data was not found */
    return (i == list->size) ? ERR : i;
}

int
al_isempty
(
    arraylist list
)
{
    checklist(list);

    return (list->size == 0) ? TRUE : FALSE;
}

/*
    Note that list->size remains unchanged, no matter what.
*/

void *
al_set
(
    arraylist list,
    int index,
    void *data,
    int size
)
{
    node *old_node = NULL;

    check_list_index_NULL(list, index);

    /* get the node presently at index: make a copy if non-NULL */
    old_node = getnode(list, index);
    if ( old_node )
    {
        /* now old_node points to a copy, not the original */
        old_node = make_node(old_node->data, old_node->data_size);
    }

    /* remove original of old node, and insert new node.  Irrelevant if
     * free_node returns NULL or not, so ignore return code. */
    (void) free_node(list, index);
    list->array[index] = make_node(data, size);

    /* return either copy or NULL */
    return old_node;
}

int
al_size
(
    arraylist list
)
{
    checklist(list);
    return list->size;
}

int
al_trim
(
    arraylist list
)
{
    node **new_array = NULL;

    checklist(list);

    new_array = (node **)malloc(list->size * sizeof(node *));
    memcheck(new_array);

    /* quickest way to copy pointers */
    memcpy(new_array, list->array, list->size * sizeof(node *));
    list->capacity = list->size;

    return OK;
}

/*!

*/

int
al_printlist
(
    arraylist list
)
{
    unsigned int i = 0;

    checklist(list);

    for( i = 0; i < list->size ; ++i)
    {
        list->print( (list->array[i])->data);
    }

    return OK;
}

void
al_destroy
(
    arraylist *list
)
{
    unsigned int i = 0;

    if (!list || !(*list))
    {
        return;
    }

    // All elements of array
    for( ; i < (*list)->size; ++i)
    {
        SMART_FREE((*list)->array[i]);
    }

    // Array
    SMART_FREE((*list)->array);

    // List
    SMART_FREE(*list);
}

