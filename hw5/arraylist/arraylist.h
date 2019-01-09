/* File: arraylist.h
 *
 * Marshall McMullen, TA provided header file
 * CS352 Summer 2004
 * University of Arizona
 *
 * This header file provides access to all of the types
 * and functions required and supported to implemented
 * a generic arraylist in C.  An arraylist is a dynamic,
 * growable array with the postive attributes of both
 * an array (speed, direct accessing of elements) and
 * a linked list (dynamic adding and growing of the strucutre).
 */

/* Provided file to help in print function pointer */
#include <print_func.h>
#include <compare_func.h>

#define DEFAULT_CAPACITY 10
#define GROW_FACTOR 2

#define TRUE 1
#define FALSE 0
#define NULL_LIST -10
#define BOUNDS -9
#define ERR -2
#define MEM_ERROR -1
#define OK 0

/*== USEFUL FUNCTION TO CHECK MEMORY AND EXIT IF FAILURE ==*/
#define memcheck(p) if(!p) do{printf("%s @ %d: Memory allocation failed!\n", __FUNCTION__, __LINE__); exit(MEM_ERROR);}while(0)

/*== TYPES ==*/
typedef struct al *arraylist;

typedef struct node {
    int data_size;
    void *data;
} node;

typedef struct al {
    int size;
    int capacity;
    node **array;
    int (*comp) (const void *, const void *);
    void (*print) (const void *);
} al;

/*== INITIALIZATION FUNCTIONS ==*/
arraylist al_init (int (*comp) (const void *, const void *), void (*print) (const void *));
arraylist al_init_size (int capacity, int (*comp) (const void *, const void *),
                        void (*print) (const void *));

/*== ADD FUNCTIONS ==*/
int al_add_at (arraylist list, int index, void *data, int size);
int al_add (arraylist list, void *data, int size);

/*== REMOVE FUNCTIONS ==*/
int al_remove (arraylist list, void *data);
int al_remove_all (arraylist list, void *data);
void *al_remove_at (arraylist list, int index);
int al_remove_range (arraylist list, int begin, int end);

/*== MISC FUNCTIONS ==*/
int al_clear (arraylist list);
int al_contains (arraylist, void *data);
int al_ensure_capacity (arraylist list, int capacity);
void *al_get (arraylist list, int index);
int al_indexof (arraylist list, void *data);
int al_isempty (arraylist list);
void *al_set (arraylist list, int index, void *data, int size);
int al_size (arraylist list);
int al_trim (arraylist list);
int al_printlist (arraylist list);
void al_destroy (arraylist *list);
