use strict;
use warnings;

my $position = 0;
my $depth    = 0;

while (<>) {
    my @input = split ' ', $_;
    $depth    += $input[1] if $input[0] eq 'down';
    $depth    -= $input[1] if $input[0] eq 'up';
    $position += $input[1] if $input[0] eq 'forward';
}

print $depth * $position;
