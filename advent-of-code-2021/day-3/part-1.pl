use strict;
use warnings;

my $count = 0;
my @bitwise_sum;

while (<>) {
    my $i = 0;
    for my $bit (split //, $_) {
        $bitwise_sum[$i]++ if $bit eq '1';
        $i++;
    }
    $count++;
}

my $gamma;
my $epsilon;

for (@bitwise_sum) {
    $gamma .= ($_ >= $count/2) ? '1' : '0';
    $epsilon .= ($_ >= $count/2) ? '0' : '1';
}

$gamma = oct("0b" . $gamma);
$epsilon = oct("0b" . $epsilon);
print $gamma * $epsilon;