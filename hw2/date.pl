#!/usr/bin/perl -w

use strict;

use Date::Calc qw(:all);

while (<>)
{
    chomp;
    print "\n";

    if ( /^#/ )
    {
        next;
    }

    my($y1,$m1,$d1,$y2,$m2,$d2);
    if ( !/(\d+)\/(\d+)\/(\d+):(\d+)\/(\d+)\/(\d+)/ )
    {
        die "Date mismatch on line '$_'\n";
    }

    ($m1,$d1,$y1,$m2,$d2,$y2) = ($1,$2,$3,$4,$5,$6);

    printf "Start Date: %2d/%2d/%4d     End Date: %2d/%2d/%4d\n",
           $m1, $d1, $y1, $m2, $d2, $y2;

    my $days = Delta_Days($y1, $m1, $d1, $y2, $m2, $d2);

    print "Delta Days == $days\n";

    # don't include end year, thus (y2-1)
    my $leap_years = 0;
    foreach my $year ($y1..($y2-1))
    {
        $leap_years += my $is_leap = leap_year($year);
=blah
        if ( ($year % 100) == 0)
        {
        if ($is_leap)
        {
            printf "Year %4d is a leap year... YES\n", $year;
        }
        else
        {
            printf "Year %4d is a leap year... NO\n", $year;
        }

        }

=blah
        if ($is_leap)
        {
            printf "Year %4d is a leap year... YES\n", $year;
        }
        else
        {
            printf "Year %4d is a leap year... NO\n", $year;
        }
=cut
    }

    printf "Total number of leap years is %4d\n", $leap_years;
}
