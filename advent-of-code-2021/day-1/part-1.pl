use strict;
use warnings;

my $res  = 0;
my $prev = "inf";
while (<>) {
    ++$res if ( $prev < $_ );
    $prev = $_;
}
print $res;
