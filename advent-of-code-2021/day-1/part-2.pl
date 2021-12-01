use strict;
use warnings;

use List::Util qw/sum/;

my @lines = <>;
my $res   = 0;
my $prev  = "inf";

for ( my $i = 0 ; $i < @lines - 2 ; $i++ ) {
    my $current = sum @lines[ $i ... $i + 2 ];
    $res++ if $prev < $current;
    $prev = $current;
}

print $res;
