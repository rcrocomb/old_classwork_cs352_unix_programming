#!/usr/bin/perl -w

use strict;

while (<>)
{
    if ( (/x.*?y/ && !/x.*y/) || (!/x.*?y/ && /x.*y/))
    {
        die "Mismatch for line: '$_'\n";
    }
}
    print "No differences for this regexp.\n";
