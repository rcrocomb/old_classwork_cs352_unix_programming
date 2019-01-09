#include <stdio.h>
#include "hashtable.h"
#include "print_func.h"

#define print(args...) do{hash_node *aa = (hash_node*) a; if (a){printf(args); return 1;} return 0;}while(0)

/* string val */
void print_s (const void *a)
{
    printf ("%s\n", (char *) a);
}

/* int val */
void print_i (const void *a)
{
    printf ("%d\n", *(int *) a);
}

/* double val */
void print_d (const void *a)
{
    printf ("%f\n", *(double *) a);
}

/* char val */
void print_c (const void *a)
{
    printf ("%c\n", *(char *) a);
}

/*====================== STRING KEYS ======================*/
int print_s_c (const void *a)
{
    print ("%s=%c\n", (char *) (aa->key), *(char *) (aa->value));
}

int print_s_i (const void *a)
{
    print ("%s=%d\n", (char *) (aa->key), *(int *) (aa->value));
}

int print_s_d (const void *a)
{
    print ("%s=%f\n", (char *) (aa->key), *(double *) (aa->value));
}

int print_s_s (const void *a)
{
    print ("%s=%s\n", (char *) (aa->key), (char *) (aa->value));
}

/*====================== INT KEYS ======================*/
int print_i_c (const void *a)
{
    print ("%d=%c\n", *(int *) (aa->key), *(char *) (aa->value));
}

int print_i_i (const void *a)
{
    print ("%d=%d\n", *(int *) (aa->key), *(int *) (aa->value));
}

int print_i_d (const void *a)
{
    print ("%d=%f\n", *(int *) (aa->key), *(double *) (aa->value));
}

int print_i_s (const void *a)
{
    print ("%d=%s\n", *(int *) (aa->key), (char *) (aa->value));
}

/*====================== DOUBLE KEYS ======================*/
int print_d_c (const void *a)
{
    print ("%f=%c\n", *(double *) (aa->key), *(char *) (aa->value));

}

int print_d_i (const void *a)
{
    print ("%f=%d\n", *(double *) (aa->key), *(int *) (aa->value));
}

int print_d_d (const void *a)
{
    print ("%f=%f\n", *(double *) (aa->key), *(double *) (aa->value));

}

int print_d_s (const void *a)
{
    print ("%f=%s\n", *(double *) (aa->key), (char *) (aa->value));

}

/*====================== CHAR KEYS ======================*/
int print_c_c (const void *a)
{
    print ("%c=%c\n", *(char *) (aa->key), *(char *) (aa->value));

}

int print_c_i (const void *a)
{
    print ("%c=%d\n", *(char *) (aa->key), *(int *) (aa->value));

}

int print_c_d (const void *a)
{
    print ("%c=%f\n", *(char *) (aa->key), *(double *) (aa->value));

}

int print_c_s (const void *a)
{
    print ("%c=%s\n", *(char *) (aa->key), (char *) (aa->value));

}
