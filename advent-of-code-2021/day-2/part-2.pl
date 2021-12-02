use strict;
use warnings;

my $position = 0;
my $depth    = 0;
my $aim      = 0;

while (<>) {
    my @input = split ' ', $_;
    $aim += $input[1] if $input[0] eq 'down';
    $aim -= $input[1] if $input[0] eq 'up';
    $position += $input[1] and $depth += $aim * $input[1]
      if $input[0] eq 'forward';
}

print $depth * $position;
