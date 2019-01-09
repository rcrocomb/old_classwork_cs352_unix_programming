/*
    Author: Robert Crocombe
    Class: CS352 Summer 2004
    Assignment: HW3 calc.c

    Big positive integer calculator.
*/

#include "calc.h"

#include <stdio.h>              /* printf(), etc. */
#include <ctype.h>              /* isalpha(), etc. */
#include <stdio.h>              /* getchar() */
#include <string.h>             /* memcpy() */
#include <stdlib.h>             /* exit() */

/*******************************************************************************
* Macros
*******************************************************************************/

/* Handy to use when initializing a brand new array */
#define ZERO_VALUE          { 1, '0' }
#define ONE_VALUE           { 1, '1' }

/* Max size of an array, including length location */
#define MAX_SIZE (MAX_DIGITS + 1)

/* I think I went a little overboard here. */
#define NUMBER_BASE 10
#define LENGTH_LOCATION 0

/* Gets the length of a varible assuming it's in the standard format */
#define LENGTH(a) (a[LENGTH_LOCATION])

/* Sets the length of a variable 's' assuming it's in the standard format*/
#define SET_LENGTH(s,a) (s[LENGTH_LOCATION] = (a))

/* Duh */
#define MAX(a,b) ( ((a) > (b)) ? (a) : (b))

/* Turns ASCII into number or visa versa */
#define DIGIT(a) ((a) - '0')
#define DIGIT_TO_ALPHA(a) ((a) + '0')

/* Can only use initializers to initialize: can't compare against
 * them, thus these two arrays.  Handy.*/
static const unsigned char ZERO_ARRAY[MAX_SIZE] = ZERO_VALUE;
static const unsigned char ONE_ARRAY[MAX_SIZE]  = ONE_VALUE;

/*******************************************************************************
* Prototypes
*******************************************************************************/

static void make_number(unsigned char dest[], unsigned char n[], const int start, const int positions);


static void die(const int code,char * message);
static int check_length(const unsigned char s[]);
static void flip(unsigned char s[]);
static int less_than(const unsigned char a[], const unsigned char b[]);
static void assign(unsigned char assign_to[],
                   const unsigned char assign_from[]);
static void increment(unsigned char a[]);
static void decrement(unsigned char a[]);


/*******************************************************************************
* Definitions
*******************************************************************************/

void
make_number(unsigned char dest[], unsigned char n[], const int start, const int positions)
{
    memcpy( dest + 1, n + (start - positions) + 1,  positions);
    SET_LENGTH(dest, positions);

    printf("From "); print_num(n); printf(" Starting at %d and taking %d"
                    " next less significant digits ", start, positions);
    printf("Result is "); print_num(dest); printf("\n");
}

/*!
    The Perl programmer in me decided to name this "die".

    This function prints the appropriate error message message based on
    the input code 'code', and additionally any error message included
    in message.  If message is null, then it's just the assigned string.
*/

void
die(const int code,char * message)
{
    char *err_string = NULL;
    switch(code)
    {
        case ERR_INPUT: err_string = "Invalid input"; break;
        case ERR_DIGIT: err_string = "Illegal digit"; break;
        case ERR_LENGTH: err_string = "Illegal number length"; break;
        case ERR_BOUNDS: err_string = "Number out of bounds"; break;
        case ERR_OPCODE: err_string = "Invalid opcode"; break;
        default: err_string = "Unknown error";
    }

    if ( message )
    {
        fprintf(stderr, "%s : %s\n", message, err_string);
    } else
    {
        fprintf(stderr, "%s\n", err_string);
    }

    exit(code);
}

/*! True if 's' has a valid length, else false */

int
check_length(const unsigned char s[])
{
    return (((LENGTH(s) <= 0) || (LENGTH(s) > MAX_DIGITS)) ? 0 : 1 );
}

/*! Increment 'a' by one, return the result in 'a'. */

void
increment(unsigned char a[])
{
    unsigned char plus_plus[MAX_SIZE] = ONE_VALUE;
    unsigned char result[MAX_SIZE];

    int status = op_plus(a, plus_plus, result);
    if ( status < ERR_OK )
    {
        die (status, NULL);
    }

    assign(a, result);
}

/*!
    Decrement 'a' by one, return the result in 'a'.

    Wrote this for the heck of it.  Actually had factorial computing from
    either direction 3! == (1*2*3) or 3! == (3*2*1), and decided the more
    "usual" way of doing things was nicer.  Otherwise, not necessary.
*/

void
decrement(unsigned char a[])
{
    unsigned char minus_minus[MAX_SIZE] = ONE_VALUE;
    unsigned char result[MAX_SIZE];

    int status = op_minus(a, minus_minus, result);
    if ( status < ERR_OK )
    {
        die (status, NULL);
    }

    assign(a, result);
}

/*!
    Multiply by 10 (well, NUMBER_BASE), essentially.  Move all digits
    one spot towards more significant.
*/

int
left_shift(unsigned char a[])
{
    unsigned char b[MAX_SIZE];

    if ( LENGTH(a) == MAX_DIGITS)
    {
        return ERR_BOUNDS;
    }

    /* Copy all digits of a into b, but one spot more significant*/
    memcpy(b + 2, a + 1, LENGTH(a));
    /* The empty least significant spot is 0. */
    b[1] = '0';
    SET_LENGTH(b, LENGTH(a) + 1);
    assign(a,b);

    return ERR_OK;
}

/* Basically op_assign(): copies from assign_from into assign_to. */

void
assign(unsigned char assign_to[], const unsigned char assign_from[])
{
    memcpy(assign_to, assign_from, LENGTH(assign_from) + 1);
}

/*
    returns 1 if a < b, else 0 (>=).
 
   Kinda chaotic, but it seemed easiest to think of comparison this way.
   Plus it should be fast, and it can be used *a lot*.
*/

int
less_than(const unsigned char a[], const unsigned char b[])
{
    if ( LENGTH(a) < LENGTH(b))
    {
        return 1;   /* if a is shorter, than it's less than b. */
    }
    else if ( LENGTH(a) > LENGTH(b))
    {
        return 0;   /* converse of the above. */
    }

    /* Know that 'a' and 'b' are the same length now. */
    unsigned int i = LENGTH_LOCATION + 1;
    for( ; i <= LENGTH(a); i++)
    {
        /* comparing ASCII is as good as using digits since they're in order */
        if ( a[LENGTH(a) - (i - 1)] > b[LENGTH(b) - (i - 1)] )
        {
            return 0;
        }
        else if ( a[LENGTH(a) - (i - 1)] < b[LENGTH(b) - (i - 1)] )
        {
            return 1;
        }
    }
    return 0;   /* Equal length and == value, therefore not less than. */
}

/*!
    When reading in a variable, it's read in backwards.  Flip it around after
    finished reading it in so it matches specified syntax.
*/

void
flip(unsigned char s[])
{
    unsigned int i = LENGTH_LOCATION + 1;
    unsigned int swap_index;
    const unsigned int stop = LENGTH(s) / 2;
    unsigned char a;

    for( ; i <= stop; i++)
    {
        swap_index = LENGTH(s) - i + 1;
        a = s[i];
        s[i] = s[swap_index];
        s[swap_index] = a;
    }
}

/*!
    Read in a really big positive integer from stdin and put it in 's'.

    EOR or '\n' terminate reading in data.  That or an error: reading in
    a non-digit, or more digits than we can handle.
*/

int
read_num(unsigned char s[])
{
    int status = ERR_OK;
    int index = LENGTH_LOCATION + 1;
    int count = 0;
    char c = getchar();

    while ( (c != EOF) && (c != ' ') && (c != '\n') )
    {
        if ( !isdigit(c) )
        {
            status = ERR_DIGIT;
            break;
        }

        if ( count > MAX_DIGITS )
        {
            status = ERR_LENGTH;
            break;
        }

        s[index] = c;
        ++count;
        ++index;

        c = getchar();
    }
    ungetc(c, stdin);


    if ( count == 0 )
    {
        status = ERR_LENGTH;
    }
    else if ( status == ERR_OK )
    {
        SET_LENGTH(s, count);
        flip(s);
        status = count;
    }

    return status;
}

/*!
    Print out the digits in 'num' assuming that it follows the correct
    data format scheme.
*/

int
print_num( unsigned char num[] )
{
    unsigned int i = LENGTH(num);
    const unsigned int stop = LENGTH_LOCATION;
    int status = check_length(num) ? ERR_OK : ERR_LENGTH;
    int count = 0;

    if (status == ERR_OK)
    {
        for( ; i > stop; --i)
        {
            if ( !isdigit(num[i]) )
            {
                status = ERR_DIGIT;
                break;
            }
            printf("%c", num[i]);
            ++count;
            status = count;
        }
    }

    return status;
}

/*!
    Semantics are: num1 + num2 => result
*/

int
op_plus
(
    unsigned char num1[],
    unsigned char num2[],
    unsigned char result[]
)
{
    unsigned int i = LENGTH_LOCATION + 1;
    unsigned int a;
    unsigned int b;
    unsigned int partial = 0;
    unsigned int count = 0;
    const unsigned int MAX_LENGTH =  MAX(LENGTH(num1), LENGTH(num2));
    int status = (check_length(num1) && check_length(num2)) ? ERR_OK : ERR_LENGTH;

    /* Lengths are okay */
    if (status == ERR_OK)
    {
        for( ; (i <= MAX_LENGTH) || partial; ++i)
        {
            /* Check for invalid digits */
            if (   ((i <= LENGTH(num1)) && !isdigit(num1[i]))
                || ((i <= LENGTH(num2)) && !isdigit(num2[i])) )
            {
                status = ERR_DIGIT;
                break;
            }

            /* Keep adding in the presence of unequal length variables */
            a = (i <= LENGTH(num1)) ? DIGIT(num1[i]) : 0;
            b = (i <= LENGTH(num2)) ? DIGIT(num2[i]) : 0;

            partial = a + b + partial;

            /* Account for carry */
            result[i] = DIGIT_TO_ALPHA(partial % NUMBER_BASE);
            partial = (partial >= NUMBER_BASE);

            ++count;
            if ( count > MAX_DIGITS )
            {
                status = ERR_BOUNDS;
                break;
            }

            status = count;
            SET_LENGTH(result, count);
        }
    }
    //printf("Op plus status == %d\n", status);
    return status;
}

/*!
    Semantics are: num1 - num2 => result
*/

int
op_minus
(
    unsigned char num1[],
    unsigned char num2[],
    unsigned char result[]
)
{
    int status = (check_length(num1) && check_length(num2)) ? ERR_OK : ERR_LENGTH;
    const unsigned int MAX_LENGTH =  MAX(LENGTH(num1), LENGTH(num2));
    unsigned int i = LENGTH_LOCATION + 1;
    unsigned int j;
    unsigned int a;
    unsigned int b;
    unsigned int carry = 0;

    /* Check again for ERR_OK so we report ERR_LENGTH if that happened first
       and so that we don't break less_than().
     */
    if ( (status == ERR_OK) && less_than(num1,num2) )
    {
        status = ERR_BOUNDS;
    }

    if (status == ERR_OK)
    {

        for( ; i <= MAX_LENGTH; ++i)
        {
            /* Oh well: checking digits anyway. */
            if (   ((i < LENGTH(num1)) && !isdigit(num1[i]))
                || ((i < LENGTH(num2)) && !isdigit(num2[i])) )
            {
                status = ERR_DIGIT;
                break;
            }

            /* Keep subtracting in the presence of unequal length variables:
             * Should never need to use 'else' portion for 'a' */
            a = (i <= LENGTH(num1)) ? DIGIT(num1[i]) : 0;
            b = (i <= LENGTH(num2)) ? DIGIT(num2[i]) : 0;

            /* Might need to carry */
            if( b > a )
            {
                /* Keep moving left until we find a non-0 or hit end:
                 * if hit end, then less_than() is broke. */
                carry = i + 1;
                while ( carry <= LENGTH(num1))
                {
                    if ( num1[carry] != '0')
                    {
                        --num1[carry];
                        /* Now subtract back to the right */
                        for( j = carry - 1; j > i; --j)
                        {
                           num1[j] += (NUMBER_BASE - 1);
                        }
                        a += NUMBER_BASE;
                        break;
                    }
                    ++carry;
                }
            }

            /* Yay.  One digit calculated. */
            result[i] = DIGIT_TO_ALPHA(a-b);
            SET_LENGTH(result, i);
        }

        /* Strip any leading 0s */
        for( i = LENGTH(result); i > (LENGTH_LOCATION+1); --i)
        {
            if( result[i] == '0')
            {
                SET_LENGTH(result, LENGTH(result) - 1);
            }
            else
            {
                break;
            }
        }
    }
    return status;
}

/*!
    Semantics are: num1 + num2 => result

    At first I had this implemented using repeated adds only.  That's a
    wee bit slow for !58 factorial, since you have to do 58! adds by one
    as the last step: not during the life of this universe.
*/

int
op_mult
(
    unsigned char num1[],
    unsigned char num2[],
    unsigned char result[]
)
{
    int status = (check_length(num1) && check_length(num2)) ? ERR_OK : ERR_LENGTH;
    unsigned char counter[MAX_SIZE] = ONE_VALUE;
    unsigned char plus_result[MAX_SIZE];
    unsigned char mult_result[MAX_SIZE];
    unsigned char small_mult[MAX_SIZE];
    unsigned char interim[MAX_SIZE];
    unsigned int i; /* Okay unless we have > 4^32 digit numbers (x86) :) */
    
    /* Use this to deal with multiplication by 1 when num2 is 1 and num1 isn't:
     * a stupid asymmetry of mine I'm not going to fix: it's right, just slow.*/
    assign(plus_result, num1);
    /* Use this for holding the value of the interim sum */
    assign(interim, num1);

    if ( status == ERR_OK )
    {
        if ( less_than(num1, ONE_ARRAY) || less_than(num2, ONE_ARRAY))
        {
            /* Multiply by 0 */
            assign(result, ZERO_ARRAY);
        } else
        {
            /* For any num1 * num2 with num2 having > 1 digit, do the
             * following */
            if( LENGTH(num2) > 1)
            {
                /* counter will hold the sums of the multiplies */
                assign(counter, ZERO_ARRAY);
                /* interim will hold num1 as it shifts to higher and
                 * high powers of 10 */
                assign(interim, num1);
                /* for every digit in num2 */
                for(i = LENGTH_LOCATION + 1; i <= LENGTH(num2); i++)
                {
                    /* Multiply the shifted version of num1 by the
                     * current digit of num2: e.g. for 46 * 12 we
                     * have:
                     * 
                     * iteration1 == (46 * 2) = 92
                     * (92 + 0 -> counter) == 92
                     * interim now becomes 460 
                     * iteration2 == (460 * 1) == 460
                     * (460 + 92 -> counter) == 552
                     * answer == 552
                     *
                     * like that.
                     */
                    SET_LENGTH(small_mult, 1);
                    small_mult[LENGTH_LOCATION + 1] = num2[i];
                    status = op_mult(interim, small_mult, mult_result);
                    if (status < ERR_OK)
                    {
                        break;
                    }

                    status = op_plus(mult_result, counter, result);
                    if (status  < ERR_OK)
                    {
                        break;
                    }

                    assign(counter, result);

                    if ( (LENGTH(interim)+ 1) > MAX_DIGITS)
                    {
                        status = ERR_BOUNDS;
                        break;
                    }
                    left_shift(interim);
                }

                if ( status > ERR_OK)
                {
                    status = LENGTH(result);
                }
            } else
            {
                /* Perform small multiplications (any size num1 times
                 * single digit num2) by repeated adds */
                while( less_than(counter, num2) )
                {
                    status = op_plus(num1, interim, plus_result);
                    assign(interim, plus_result);
    
                    if ( status < ERR_OK )
                    {
                        break;
                    }
    
                    increment(counter);
                }

                assign(result, interim);
                if ( status >= ERR_OK )
                {
                    status = LENGTH(result);
                }
            }
        }
    }
    return status;
}

/*!
    Semantics is num1 / num2 => result.

    The result is *integer* division: no remainder.

    Slow.  Will fix if time.  Didn't even think about this issue.  Duh.
*/

int
op_div
(
    unsigned char num1[],
    unsigned char num2[],
    unsigned char result[]
)
{
    unsigned char counter[MAX_SIZE] = ZERO_VALUE;
    unsigned char minus_result[MAX_SIZE];

    unsigned char x[MAX_SIZE] = {};
    unsigned char y[MAX_SIZE] = {};
    unsigned char z[MAX_SIZE] = {};
    unsigned char save[MAX_SIZE] = {};

    int status = (check_length(num1) && check_length(num2)) ? ERR_OK : ERR_LENGTH;

    /* trying to divide by zero */
    if ( !less_than(counter, num2))
    {
        status = ERR_BOUNDS;
    }

    if ( status == ERR_OK )
    {
        /* If num1 is < num2, then result is 0. */
        if ( less_than(num1,num2) )
        {
            assign(result,ZERO_ARRAY);
            return LENGTH(result);
        }

        int arg = 0;
        int position = LENGTH(num1);
        //assign(result, ONE_ARRAY);
        memset(result + 1, '0', MAX_DIGITS);
        assign(z, num1);
        assign(save, num1);
        do
        {
            int counts = 1;
        top:
            assign(save,z);
            if( counts <= LENGTH(num1))
            {
            make_number(x, z, position, counts);
            
            while ( less_than(x,num2) )
            {
                ++counts;
                printf("Continuing with counts == %d\n", counts);
                goto top;
            }
            }

            assign(z, x);
            printf("Found something to divide: ");
            print_num(z); 
            printf(" by ");
            print_num(num2);
            printf(" with count == %d\n", counts);

            /* Perform division by repeated subtraction */
            assign(counter, ZERO_ARRAY);
            while ( !less_than(z, num2) )
            {
                status = op_minus(z, num2, minus_result);        
                assign(z, minus_result);

                printf("z == "); print_num(z);
                printf("\n");

                if ( status < ERR_OK )
                {
                    break;
                }

                increment(counter);
            }

            printf("Result of division is == ");
            print_num(counter);
            printf("\n");

            int digit_position = position - (counts - 1);
            printf("Assigning this result to digit %d\n",digit_position);

            if ( digit_position < 1)
            {
                printf("Shit is broke\n");
                break;
            }


            result[digit_position] = counter[1];
            if (LENGTH(result) < digit_position)
            {
                printf("Setting result's length to %d\n", digit_position);
                SET_LENGTH(result, digit_position);
            }

            //printf("Partial result looks like ");
            //print_num(result);
            //printf("\n");

            printf("[%3d] == %02x\n", 0, result[0]);
            for(int j = 1; j < 10; j++)
            {
                printf("[%3d] == %c '%02x'\n", j, result[j], result[j]);
            }

            //break;

            // Now calculate the remainder

            op_mult(counter, num2, y);

            op_minus(x, y, z);

            printf("From ");
            print_num(x);
            printf(" subtract result of multiplying ");
            print_num(counter);
            printf(" and ");
            print_num(num2);
            printf(" == ");
            print_num(y);
            printf(" to obtain remainder == ");
            print_num(z);
            printf("\n");

            printf("Length == %d ", LENGTH(save));
            printf("Counts == %d\n", counts);
            int top = LENGTH(save) - counts;
            for(int a = 0; a < (LENGTH(save)-counts); ++a)
            {
                left_shift(z);

                //int low_digit_spot = LENGTH(num1) - (position-1);
                int low_digit_spot = digit_position - 1 -a;

                printf("The low digit spot is %d ", low_digit_spot);

                if ( low_digit_spot <= 1)
                {
                    printf("Assign the value %c\n", num1[low_digit_spot]);
                    z[1] = num1[low_digit_spot];
                    printf("No place to carry to.  Division done.\n");
                    break;
                }
                
                printf("Assign the value %c\n", num1[low_digit_spot]);
                z[1] = num1[low_digit_spot];

            }
            if (less_than(z,num2)) //&& (top == 0))//(LENGTH(save) > 1))
            {
                left_shift(z);
                z[1] = '0';
            }
            if (less_than(z,num2))
            {
                break;
            }

            printf("After shifting and combining, the new number is '");
            print_num(z);
            printf("'\n");

            position = LENGTH(z);
            printf("End of loop\n\n");
            ++arg;

        } while (position > 1);
out:
        ;
#if 0
        assign(result, ONE_ARRAY);

        /* Perform division by repeated subtraction */
        while ( !less_than(num1, num2) )
        {
            status = op_minus(num1, num2, minus_result);        
            assign(num1, minus_result);

            if ( status < ERR_OK )
            {
                break;
            }

            increment(counter);
        }

        if ( status >= ERR_OK )
        {
            status = LENGTH(counter);
            assign(result, counter);
        }
#endif
    }
    return status;
}


/*!
    Semantics num1! => result, where ! is factorial, not logical negation.

    Okay, sped up now that op_mult() doesn't suck.
*/

int
op_fact
(
    unsigned char num1[],
    unsigned char result[]
)
{

    unsigned char mult_result[MAX_SIZE];
    unsigned char counter[MAX_SIZE];
    unsigned char interim[MAX_SIZE];

    int status = check_length(num1) ? ERR_OK : ERR_LENGTH;
    if ( status == ERR_OK )
    {
        assign(interim, num1);
        assign(counter, num1);

        if (less_than(counter, ONE_ARRAY))
        {
            /* 0! is special case */
            assign(interim, ONE_ARRAY);
        } else
        {
            decrement(counter);
        }

        /* Compute factorial by repeated multiplication: shock! */
        while ( !less_than(counter, ONE_ARRAY))
        {
            status = op_mult(counter, interim, mult_result);        
            assign(interim, mult_result);

            if ( status < ERR_OK )
            {
                break;
            }
            decrement(counter);
        }

        /* Propogate any error status stuff */
        if ( status > ERR_OK )
        {
            status = LENGTH(interim);
            assign(result, interim);
        }
    }
    return status;
}

/*!
    The main deal.  Does the following:

    1. Figures out which operation we are performing: deals with errors
       related to invalid syntax.
    2. Gets the first value for the operation.
    3. If the operation is not factorial (!), get the second value.
    4. Performs the requested operation.
    5. Prints the results (if any).
    6. Terminates.
*/

int
main
(
    int argc,
    char *argv[]
)
{
    char c = getchar();
    int status = 0;
    int state = 0;
    char opcode = 0;

    /* Initialize the necessary variables */
    unsigned char var1[MAX_DIGITS + 1];
    unsigned char var2[MAX_DIGITS + 1];
    unsigned char result[MAX_DIGITS + 1] = { 1, '1'};

    /* Get arguments for operation: state machine */
    while ( c != EOF )
    {
        switch(state)   /* Input state machine */
        {
            case 0:     /* Get opcode */
                switch(c)
                {
                case '+':   /* fall through*/
                case '-':   /* fall through*/
                case '*':   /* fall through*/
                case '/':   /* fall through*/
                case '!':
                    opcode = c;
                    break;
                default:
                    die(ERR_OPCODE, NULL);
                }
                state = 1;
                break;
            case 1:     /* Get num1 */
                while ( c == ' ') { c = getchar(); } /* devour spaces */
                /* We got the first non-space char: need to put it
                 * back so read_num() can get it. */
                ungetc(c, stdin);
                status = read_num(var1);
                if ( status < ERR_OK)
                {
                    die(status, NULL);
                }
                state = 2;
                break;
            case 2:     /* Get num2 */
                while ( c == ' ') { c = getchar(); } /* as above */
                ungetc(c, stdin);

                /* Whoops.  Only entered one number: if this isn't
                 * here, then read_input() fails with invalid length,
                 * which I think is incorrect. */
                if ( (c == EOF) || (c == '\n'))
                {
                    die(ERR_INPUT, NULL);
                }

                /* Don't want to get an ERR_LENGTH on this opcode */
                if ( (opcode == '!') )
                {
                    if ( read_num(var2) > ERR_OK)
                    {
                        die(ERR_INPUT, NULL);
                    }
                    state = 3;
                    break;
                }

                status = read_num(var2);
                if ( status < ERR_OK)
                {
                    die(status, NULL);
                }

                state = 3;
                break;
            case 3:     /* It's an error to find text here */
                if ( c != '\n')
                {
                    die(ERR_INPUT, NULL);
                }
        }
        c = getchar();
    }


    switch(opcode)
    {
        case '+': status = op_plus(var1, var2, result); break;
        case '-': status = op_minus(var1, var2, result); break;
        case '*': status = op_mult(var1, var2, result); break;
        case '/': status = op_div(var1, var2, result); break;
        case '!': status = op_fact(var1, result); break;
    }

    if ( status < ERR_OK)
    {
        die(status, NULL);
    }

    printf("= ");
    print_num(result);
    printf("\n");

    return ERR_OK;
}

