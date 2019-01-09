#include <stdio.h>                      /* printf, scanf    */
#include <stdlib.h>

/*******************************************************************************
*                                                                              *
* Author: Robert Crocombe                                                      *
* Class: CS352                                                                 *
* Assignment: HW#2 -- days.c                                                   *
*                                                                              *
* Performs a number of calculations on the interval between a starting and     *
* ending date: number of days, number of leap years, and a breakdown of the    *
* number of years, months, and days.                                           *
*******************************************************************************/

/*******************************************************************************
* Typedefs                                                                     *
*******************************************************************************/

typedef unsigned int year_t;
typedef unsigned int month_t;
typedef unsigned int day_t;
typedef unsigned int boolean;

/*******************************************************************************
* Constants                                                                    *
*******************************************************************************/

static const year_t  YEARS_PER_LEAP         = 4;
static const month_t MONTHS_PER_YEAR        = 12;
static const day_t   DAYS_PER_YEAR          = 365;
static const year_t  YEARS_PER_CENTURY      = 100;
static const year_t  LEAP_YEARS_PER_CENTURY = 25;

static const boolean TRUE                   = 1;
static const boolean FALSE                  = 0;

const unsigned int DAYS_IN_YEAR[2][14] =
{
    { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },/* non  */
    { 0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 } /* leap */
};

const unsigned int DAYS_IN_MONTH[2][13] =
{
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },  /* leap year */
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }   /* non      */
};

/*******************************************************************************
* Prototypes                                                                   *
*******************************************************************************/

day_t year_to_days( const year_t year );
boolean leap_year( const year_t year );
year_t leap_years ( const year_t year1, const year_t year2 );
day_t date_to_days( const year_t year, const month_t month, const day_t day);
day_t delta_days ( const year_t year1, const month_t month1, const day_t day1,
                   const year_t year2, const month_t month2, const day_t day2);
void delta_year_month_day(
    year_t * const year1, month_t * const month1, day_t * const day1,
    const year_t year2, const month_t month2, const day_t day2);
void perform_calculations(
    const year_t year1, const month_t month1, const day_t day1,
    const year_t year2, const month_t month2, const day_t day2);


void gimme_numbers(
    const year_t year1, const month_t month1, const day_t day1,
    const year_t year2, const month_t month2, const day_t day2);
/*******************************************************************************
* Definitions                                                                  *
*******************************************************************************/

/*
    From the year "year", figures out how many days there have been since
    day 0 up until the end of the current year.  There's some double-counting
    that is eventually filtered out: e.g., we initially subtract out modulo
    400 century years as non-leap, but then add them back in the next line
    down.
 */

day_t
year_to_days( const year_t year )
{
    year_t y = year >> 2;           /* divide by 4 to find leap years   */
    day_t days;

    days = year * DAYS_PER_YEAR;    /* regular years                    */

    days += y;                      /* leap years                       */

    y /= LEAP_YEARS_PER_CENTURY;    /* y is now # of centuries          */
    days -= y;                      /* century non-leap years           */

    days += y >> 2;                 /* modulo 400 century leap years    */

    return (days);
}

/*
    Returns TRUE if the year "year" is a leap year, or "FALSE" if "year" is
    not a leap year.

    I think the logic comes out to be self explanatory by the time you get
    to the return statement.  Hopefully the math isn't too obscure.
*/

boolean
leap_year( const year_t year )
{
    /* centuries      */
    const year_t centuries  = year / YEARS_PER_CENTURY;

    /* like 1600, etc.*/
    const boolean is_modulo_400_century = ((centuries & 0x03) == 0);

    /* true if % 4 */
    const boolean is_leap_year = ((year & 0x03) == 0);

    const boolean not_century_year =  (  ( year / YEARS_PER_CENTURY )
                                       * YEARS_PER_CENTURY)             != year;

    return ( is_leap_year && (not_century_year || is_modulo_400_century) );
}

/*
    Given two years, figure out how many leap years have occured in the
    intervening period.  Return this number.
*/

year_t
leap_years
(
    const year_t year1,
    const year_t year2
)
{
#if 1
    year_t dc = 0;
    year_t i = year1;
    year_t leaps = 0;
    year_t years = year2 - year1;
    //year_t centuries = years / YEARS_PER_CENTURY;
    year_t centuries;

    year_t year1_next_century = (year1 / YEARS_PER_CENTURY) * YEARS_PER_CENTURY;
    year_t year2_century = (year2 / YEARS_PER_CENTURY) * YEARS_PER_CENTURY;

    year1_next_century += (year1_next_century != year1) * YEARS_PER_CENTURY;

    if ( year2 < year1_next_century )
    {
        year1_next_century = year2;
        year2_century = year2;
    }

    centuries = (year2_century - year1_next_century) / YEARS_PER_CENTURY;
    centuries;
    printf("Years == %4u Centuries == %4u\n", years, centuries);

    printf("From %4u to %4u\n", i, year1_next_century);

    /* <= 100 iterations */
    for( ; i < year1_next_century; i++)
    {
        leaps += leap_year(i);
    }

    printf("Leaps == %4u\n", leaps);

    /* Now we're at the century boundary.  Do by century to last century
     * before year2. */

    if (centuries)
    {
        int value = 0;
        for (i = year1_next_century; i < year2_century; i += YEARS_PER_CENTURY)
        {
            value += LEAP_YEARS_PER_CENTURY;
            if ( (i % 400) != 0)
            {
                --value;
            }
        }
        leaps += value;
    }

    printf("Leaps == %4u\n", leaps);

    /* Now at century boundary before year2.  Count some more.
     * <= 100 iterations */
    printf("From %4u to %4u\n", i, year2);
    for( ; i < year2; i++)
    {
        leaps += leap_year(i);
    }

    printf("Leaps == %4u\n", leaps);

#else
    year_t leaps = 0;
    year_t years = year2 - year1;
    year_t year2_century = (year2 / YEARS_PER_CENTURY) * YEARS_PER_CENTURY;

    year_t i = year1;
    year_t dc = 0;

    /* Number of full centuries between start and end */
    year_t centuries = years / YEARS_PER_CENTURY;

    //printf("centuries == %4u years == %4u\n", centuries, years);

    if ( centuries )
    {
        /* Assume that all % 4 years are leap years */
        leaps = centuries * LEAP_YEARS_PER_CENTURY;

        printf("Naive leaps == %4u\n", leaps);

        /* Find nearest century year*/
        year_t century = (year1 / YEARS_PER_CENTURY) * YEARS_PER_CENTURY;

        /* If this century was behind us, then advance to next century since
        * obviously there's no intervening century leap year for that century */
        century += (century != year1) * YEARS_PER_CENTURY;
        printf("Nearest century == %4u\n", century);

        years -= centuries * YEARS_PER_CENTURY;
        i += centuries * YEARS_PER_CENTURY;

        printf("Number == %4u years == %4u\n",
                i,
                years);
/*
        printf("Year2 century == %4u\n", year2_century);
        if ( year2_century < i )
        {
            year2_century -= YEARS_PER_CENTURY;
        }
*/
        printf("Year2 century == %4u\n", year2_century);

        /* already added %4 leap years, remove those for non %400 centuries */
        //for( ; century <= year2_century; century += YEARS_PER_CENTURY )
        for( ; century < year2_century; century += YEARS_PER_CENTURY )
        {
            boolean is = leap_year(century);
            if ( is )
            {
                printf("Year %4u is a leap year... YES: %4u\n", century, leaps);
            } else
            {
                --leaps;
                printf("Year %4u is a leap year...  NO: %4u\n", century, leaps);
            }
            //leaps -= !leap_year(century);
            //printf("For year %4u: leaps after == %4u\n", century, leaps);
        }

        printf("Years == %4u    Leap Years == %4u\n", years, leaps);

        printf("After century check: remaining years is %4u -- start is %4u\n", years, i);

    }

    if (years > YEARS_PER_LEAP)
    {
        int found = 0;
        boolean is = 0;
        /* Diff was < century, but > 4 years. Check %4 years (< 25 iterations)*/

        /* Find nearest %4 year not in the past (could be year1) */
        years = i & ~0x3;
        years += (years != i ) * YEARS_PER_LEAP;

        for ( ; years < year2; years += YEARS_PER_LEAP)
        {
            //leaps += leap_year(years);
            is = leap_year(years);
            leaps += is;
            if ( is )
            {
                ++found;
            }
            printf("Found == Year %4u ...   %4d\n", years, found);
        }
    } else
    {
        /* For tiny intervals (< 4 years), just check each year individually */
        for( ; i < year2; i++)
        {
            leaps += leap_year(i);
        }
    }
#endif
    //printf("Leaps so far == %4u\n", leaps);

    for(i = year1; i < year2; i++)
    {
        dc += leap_year(i);
    }

    //printf("Double check reveals == %4u\n", dc);

    if (dc != leaps )
    {
        printf("Found %4u but double-checked as %4u\n", leaps, dc);
        exit(0);
    }

    return leaps;

}

/*
    Given a year, month, and day, figure out how many days it has been since
    day 0 up to the specified period.  Return this value.
*/

day_t
date_to_days
(
    const year_t year,
    const month_t month,
    const day_t day
)
{
    boolean leap = leap_year(year);
    return ( year_to_days( year - 1 ) + DAYS_IN_YEAR[leap][month] + day );
}

/*
    Given two dates specified as "year, month, and day", figure out how
    many days there are between the two periods.  Assumes that the second
    value is after the first value.

    Returns this number of days.
*/

day_t
delta_days
(
    const year_t year1, const month_t month1, const day_t day1,
    const year_t year2, const month_t month2, const day_t day2
)
{
    return (  date_to_days(year2, month2, day2)
            - date_to_days(year1, month1, day1) );
}

/*
    Given two dates specified as "year, month, and day", figure out
    how many years, months, and days are between the two dates.  These values
    are returned in the variables of the starting date.
*/

void
delta_year_month_day
(
    year_t * const year1, month_t * const month1, day_t * const day1,
    const year_t year2, const month_t month2, const day_t day2
)
{
    /* naive difference: some values could be negative      */
    int days = day2 - *day1;
    int months = month2 - *month1;
    int years = year2 - *year1;

    boolean leap = leap_year(year2);
    month_t i;

    /* same date for both */
    if ( !(days || months || years) )
    {
        *year1 = *month1 = *day1 = 0;
        return;
    }

    /* Now fix any negative values by rejiggering days and months to + values */

    /* Cannot have negative days between dates unless start == end */
    if ( days < 0 )
    {
        for ( i = 1; i <= MONTHS_PER_YEAR; i++ )
        {
            if ( ((day_t)-days) < DAYS_IN_YEAR[leap][i] )
            {
                days += DAYS_IN_YEAR[leap][i];
                months -= (i - 1);
                break;
            }
        }
    }

    /* Cannot have negative months difference, obviously. */
    if ( months < 0 )
    {
        months += MONTHS_PER_YEAR;
        --years;
    }

    *year1 = years;
    *month1 = months;
    *day1 = days;
}

/*
    Drives the brains of the calculations, plus does the pretty printing.
*/

void
perform_calculations
(
    const year_t year1, const month_t month1, const day_t day1,
    const year_t year2, const month_t month2, const day_t day2
)
{
    const char *BOX_EDGE = "+------------------------------------------------+";
    const char *SUMMARY  = "|                    SUMMARY                     |";

    const day_t days_difference = delta_days(year1, month1, day1,
                                             year2, month2, day2);

    const year_t number_leap_years = leap_years( year1, year2 );

    year_t year_diff = year1;
    month_t month_diff = month1;
    day_t day_diff = day1;

    delta_year_month_day( &year_diff, &month_diff, &day_diff,
                           year2, month2, day2);

    printf( "%s\n%s\n%s\n", BOX_EDGE, SUMMARY, BOX_EDGE );

    /* Junk goes here*/
    printf(" * %u day(s) between %u/%u/%u and %u/%u/%u\n",
           days_difference,
           month1, day1, year1,
           month2, day2, year2);

    printf(" * Leap Years: %u\n", number_leap_years);
    printf(" * Breakdown: %u year(s), %u month(s), %u day(s)\n",
              year_diff, month_diff, day_diff);

    printf( "%s\n", BOX_EDGE );
}

void gimme_numbers(
    const year_t year1, const month_t month1, const day_t day1,
    const year_t year2, const month_t month2, const day_t day2)
{
    printf("Start: %04u-%02u-%02u End: %04u-%02u-%02u\n",
            year1, month1, day1, year2, month2, day2);

    const day_t days_difference = delta_days(year1, month1, day1,
                                             year2, month2, day2);

    const year_t number_leap_years = leap_years( year1, year2 );

    year_t year_diff = year1;
    month_t month_diff = month1;
    day_t day_diff = day1;

    delta_year_month_day( &year_diff, &month_diff, &day_diff,
                           year2, month2, day2);

    printf("Days == %10u Leap == %04u Y == %04u M == %02u D == %02u\n",
           days_difference, number_leap_years, year_diff, month_diff, day_diff);
}


int
main
(
    int argc,
    char *argv[]
)
{
    year_t year1, year2;
    month_t month1, month2;
    day_t day1, day2;
/*
    printf("Start date: ");
    scanf("%u/%u/%u", &month1, &day1, &year1);
    printf("End date: ");
    scanf("%u/%u/%u", &month2, &day2, &year2);

    perform_calculations(year1, month1, day1, year2, month2, day2);
*/
    const unsigned int MAX_DIFF = 12000;
    const unsigned int MAX_YEAR  = 32000;
    const unsigned int MAX_MONTH = 12;

    const unsigned int ITERATIONS = argv[1] ? atoi(argv[1]) : 10;
    unsigned int i = 0;
    for( ; i < ITERATIONS; i++)
    {
        printf("\n\nIteration == %4u\n\n", i);

        year1 = (year_t)(drand48() * MAX_YEAR) + 1;
        year2 = year1 + (year_t)(drand48() * MAX_DIFF);
        year2 = (year2 > MAX_YEAR) ? MAX_YEAR : year2;

        month1 = (int)(drand48() * MAX_MONTH) + 1;
        month2 = (int)(drand48() * MAX_MONTH) + 1;

        day1 = (day_t)(drand48() * DAYS_IN_MONTH[leap_year(year1)][month1]) + 1;
        day2 = (day_t)(drand48() * DAYS_IN_MONTH[leap_year(year2)][month2]) + 1;

        if( (year1 <= 0) || (year2 <= 0) || (month1 <= 0) || (month2 <= 0) || (day1 <= 0) || (day2 <= 0) || (year2 < year1))
        {
            printf("Failure: %04u-%02u-%02u | %04u-%02u-%02u\n",
                   year1, month1, day1, year2, month2, day2);
            exit(0);
        } else
        {
            gimme_numbers(year1, month1, day1, year2, month2, day2);
        }

    }

    return ( 0 );
}

