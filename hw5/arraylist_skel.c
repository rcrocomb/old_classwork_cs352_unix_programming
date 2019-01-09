/* File: arraylist.c
 *
 * Marshall McMullen, TA provided skelaton file
 * CS352 Summer 2004
 * University of Arizona
 *
 * This C file provides access to all of the types
 * and functions required and supported to implemented
 * a generic arraylist in C.  An arraylist is a dynamic,
 * growable array with the postive attributes of both
 * an array (speed, direct accessing of elements) and 
 * a linked list (dynamic adding and growing of the strucutre).
 */
#include <stdlib.h>
#include <arraylist.h>
#include <string.h>

/* THESE MACROS SHOULD MAKE IT EASY FOR YOU TO CHECK THE VALIDITY OF 
 * PARAMETERS TO CERTAIN FUNCTIONS.  YOU DO NOT HAVE TO USE THESE, BUT THEY
 * ARE MEANT TO HELP YOU.  YOU CALL A MACRO JUST LIKE YOU WOULD A FUNCTION.
 */
#define checksize(list) do{if(list->size == list->capacity)grow(list);}while(0)
#define checklist(list) do{if(!list) return NULL_LIST;}while(0)
#define check(err) do{if(err != OK) return err;}while(0)
#define checkindex(list, i) do{if(i < 0 || i > list->size) return BOUNDS;}while(0)
#define check_list_index(list, i) do{checklist(list); checkindex(list, i);}while(0)
#define check_list_index_NULL(list, i) do{if(!list || (i < 0 || i > list->size)) return NULL;}while(0)

/* STATIC FUNCTION PROTOTYPES */
static int shift (arraylist list, int index);
static int remove_hole (arraylist list, int);
static int grow (arraylist list);
static node *make_node (void *data, int size);
static int free_node (arraylist list, int index);
static void *getdata (arraylist list, int index);
static int getdata_size (arraylist list, int index);
static node *getnode (arraylist list, int index);

/*== INITIALIZATION FUNCTIONS ==*/
arraylist al_init (int (*comp) (const void *, const void *), void (*print) (const void *))
{
    return al_init_size (DEFAULT_CAPACITY, comp, print);
}

arraylist al_init_size (int capacity, int (*comp) (const void *, const void *),
                        void (*print) (const void *))
{
    /* Allocate space for the arraylist itself */
    arraylist newlist = (arraylist) malloc (sizeof (al));

    /* Ensure malloc succeeded */
    memcheck (newlist);

  /** FIXME: Set all the fields in newlist **/

    /* We're done, return the new list */
    return newlist;
}

/*== ADD FUNCTIONS ==*/
int al_add_at (arraylist list, int index, void *data, int size)
{
  /* Ensure the list indexes are valid */
  check_list_index (list, index);

  /** FIXME: shift over all elements to the right of 'index' 
      to make room to insert this new node.  This may also
      require resizing array if it is not big enough!  You should 
      initiate this by calling the "shift" function, which should
      in-turn check to ensure there is enough room to shift, and grow
      if necessary
  **/

  /** FIXME: Create a new node using the data and the size. I HIGHLY
      suggest you make use of the 'make_node' function I provided 
      (see below)
  **/

  /** FIXME: NOW, insert the new node into the arraylist at the end
      of the array.  Then increment the size of the arraylist.
  **/

    /* All is well, return 'OK' */
    return OK;
}

int al_add (arraylist list, void *data, int size)
{

  /** FIXME: Add the data/size to the next slot in
      the arraylist.  DON'T re-invent the wheel -- you
      have a function that will do this already!!
  **/

    return OK;
}

/* NOT REQUIRED...BUT VERY HELPFUL */
static int shift (arraylist list, int index)
{
    /* Ensure the list indexes are valid */
    check_list_index (list, index);

  /** FIXME: Grow array if we need to **/

  /** Shift each element down one to the right
      to create a hole at 'index'
  **/

    /* We're done, return */
    return OK;
}

/* NOT REQUIRED...BUT VERY HELPFUL */
static int remove_hole (arraylist list, int index)
{
    /* Ensure the list indexes are valid */
    check_list_index (list, index);

  /** FIXME: shift all elements to the RIGHT of
      'index' LEFT to fill a hole created as a
      result of a remove operation
  **/

    return OK;
}

static int grow (arraylist list)
{
    /* Ensure the list indexes are valid */
    checklist (list);

    int new_capacity = GROW_FACTOR * list->size;

  /** FIXME: Create a new array of size 'new_capacity'
      and then copy over all the elements from the
      arraylist's array into the new larger array,
      then update the pointer in arraylist to point
      to the new larger array. Don't forget to 
      clean up any data structures not needed after
      the copy
  **/

    retrun OK;
}

/*== REMOVE FUNCTIONS ==*/
int al_remove (arraylist list, void *data)
{
    /* Ensure the list indexes are valid */
    checklist (list);

  /**FIXME: Itereate through the arraylist, and use
     the 'comp' function to see if the requested
     data is found.  IF so, call 'free_node' 
     (provided -- see below) on that list and index.  
     Any leftover hole as a result of the remove should
     be filled in by shifting all elements to the left to
     fill in the hole.

     return 1 if removal accomplished, else 0.

  **/

    return 0;
}

int al_remove_all (arraylist list, void *data)
{
    /* Ensure the list indexes are valid */
    checklist (list);

    int success = FALSE;

  /** FIXME: Remove all occurrances of 'data' from
      the arraylist. Follow the same rules as described
      in al_remove
  **/

    return TRUE;
}

void *al_remove_at (arraylist list, int index)
{
    /* Ensure all parameters are valid */
    if (!list || (index < 0 || index > list->size))
        return NULL;

    void *data;

  /** FIXME:  Here, you need to basically just call 'free_node'
      on the index in the list that they want to remove.  HOWEVER,
      YOU ALSO NEED to figure out how to ALSO return the data contained
      in the node they want to delete.  Bear in mind that after the
      call to 'free_node', the contents of that memory will be
      obliterated.
  **/

    return data;
}

int al_remove_range (arraylist list, int begin, int end)
{

  /** FIXME: CHECK TO MAKE SURE ALL PARAMETERS AND BOUNDS
      ARE CORRECt!
  **/

  /** FIXME: Itereate over the list and remove each element
      within the range [begin, end).  Note, this means
      begin should be removed, but 'end' should NOT.
  **/

    return OK;
}

/*== MISC FUNCTIONS ==*/
int al_clear (arraylist list)
{
    checklist (list);

  /** FIXME: Itereate over the list and
      remove each element. Size should be 0 afterwards.
  **/

    return OK;
}

void al_destroy (arraylist *list)
{
  if(!list)
    return;

  /* FIXME: first clear the arraylist */

  /* NOW -- free the arraylist itself */
  /* DON't forget to set list to NULL so that subsequent
     function calls on "list" will fail -- returning NULL_LIST
  */
}

int al_contains (arraylist list, void *data)
{
    checklist (list);

  /** FIXME: Itereate over the list and use list->comp
      to see if the given node you are on has 'data' in
      its node.  If it does, return TRUE, else return FALSE
      when you reach the end.
  **/

    return FALSE;
}

int al_ensure_capacity (arraylist list, int capacity)
{
    checklist (list);

    int new_capacity = capacity;

  /** FIXME: This function should ensure that the arraylist
      has a minimum capacity of 'capacity'.  Note, if it is already
      larger than (or equal to) 'capacity', do nothing.  Otherwise,
      you will have to grow the array and copy the new elements and
      update the pointer for the array in the arraylist.
  **/

    return OK;
}

void *al_get (arraylist list, int index)
{
  /** FIXME: Simply get the void * stored in the node
      at 'index' and return it.  NOTE: DO NOT COPY this into
      a new void * and return the new one, just return whatever
      is in the arraylist.  This way, the caller CAN modify the
      data and it will not need to be re-inserted, all changes 
      are made to both 
  **/

    return NULL;                // <==== PLACE HOLDER! FIX THIS!
}

int al_indexof (arraylist list, void *data)
{

  /** FIXME: Find the index of 'data' in the
      arraylist.  return -1 if it is not
      found in the arraylist.
  **/

    return -1;
}

int al_isempty (arraylist list)
{

  /** FIXME: Return TRUE if the list's size is 0, else return FALSE **/

    return TRUE;                // <==== PLACEHOLDER, CHANGE THIS!
}

void *al_set (arraylist list, int index, void *data, int size)
{
    check_list_index_NULL (list, index);

  /** FIXME: set's the node at 'index' to a new node
      that is created from 'data' and 'size'.  However, we cannot
      just blindly create a new node and then obliterate what
      was previously stored there... because we must RETURN
      the OLD VOID * that was stored at that index!
  **/

    return NULL;                // <===== PLACEHOLDER, CHANGE THIS!
}

int al_size (arraylist list)
{

  /** FIXME: Return the size (not the capacity) of the arraylist **/

    return -1;                  // <=========== PLACEHOLDER, CHANGE THIS!
}

int al_trim (arraylist list)
{

  /** FIXME: trim's the arraylist down so that capacity == size.  You
      should create a smaller array of size 'list->size' and copy all
      the elements to that new array.  Then updat the pointers.  Make
      sure you free any un-needed datastructures.
  **/

    return OK;                  // <============ PLACEHOLDER, CHANGE THIS!!
}

int al_printlist (arraylist list)
{

  /** FIXME: Prints the contents of the arryalist in the following
      form (identical to Java's:

      [val1, val2, val3, val4]

  **/

    return 0;
}

/****************************************************************************************
 * PROVIDED STATIC HELPER FUNCTIONS --- EXTREMELY USEFUL!!!!
 ****************************************************************************************/


/* PROVIDED HELPER FUNCTION TO HELP YOU GET THE SIZE
 * OF A GIVEN INDEX IN THE ARRAYLIST.
 */
static int getdata_size (arraylist list, int index)
{
    /* Ensure indexes are valid */
    check_list_index (list, index);

  /** Get a node from the list && index using
      getnode function. This example should be
      used to help you anywhere else in your code
      where you want to convert an index in the arraylist
      into a node.
  **/
    node *n = getnode (list, index);

    /* If the node is NULL, just return 0 */
    if (!n)
        return 0;

    /* Return the size stored in that node */
    return n->data_size;
}

/* PROVIDED HELPER FUNCTION TO HELP YOU GET THE DATA
 * OF A GIVEN INDEX IN THE ARRAYLIST.  THIS RETURNS
 * THE VOID * STORED AT THE SPECIFIED INDEX IN THE
 * ARRAYLIST.
 */
static void *getdata (arraylist list, int index)
{
    /* Check to ensure all parameters are valid! */
    if (!list || (index < 0 || index > list->size))
        return NULL;

    /* Get the node at the required index */
    node *n = getnode (list, index);

    /* If it is null, return NULL */
    if (!n)
        return NULL;

    /* GET the data stored in the node */
    void *v = n->data;

    /* Return the pointer to the data */
    return v;
}


/* PROVIDED HELPER FUNCTION TO HELP YOU GET PARSE ONE
 * INDEX IN THE ARRAYLIST INTO A NODE.
 */
static node *getnode (arraylist list, int index)
{
    /* Check to ensure all parameters are valid! */
    if (!list || (index < 0 || index > list->size))
        return NULL;

    /* Get the node at the required index */
    node *n = *(list->array + index);

    /* Return the node */
    return n;
}

/* PROVIDED HELPER FUNCTION TO HELP YOU ==>CREATE<== A NODE
 * USING THE ACTUAL DATA AND THE SIZE OF THAT DATA.  ONCE
 * YOU HAVE A NODE, THE NODE CAN THEN BE INSERTED INTO THE
 * ARRAYLIST.
 */
static node *make_node (void *data, int size)
{
    /* Malloc off space for a node */
    node *n = (node *) malloc (sizeof (node));

    /* Make sure malloc succeeded */
    memcheck (n);

    /* ALSO! Must malloc off space for the DATA!! */
    n->data = malloc (size);
    memcheck (n->data);

    memcpy (n->data, data, size);
    n->data_size = size;

    return n;
}


/* PROVIDED HELPER FUNCTION TO FREE THE MEMORY ** USED TO STORE A NODE AND THE DATA IN THAT
 * NODE 
 */
static int free_node (arraylist list, int index) {
  check_list_index (list, index);

  node *n = getnode (list, index);
  
  if (n) {
    void *v = n->data;
    memset (v, 0, n->data_size);
    free (v);
    v = NULL;
  }
  
  free (n);
  n = NULL;
  
  return OK;
}

