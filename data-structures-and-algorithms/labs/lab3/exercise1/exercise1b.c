#include <stdio.h>

char bits;

void printAddress(int *c) {
    printf("%u\n", c);
}

void p(int n) {
    if (n == 270000) return;
    printAddress(&n);
    p(n+1);
}

int main() {
   p(0);
   return 0;
}

// Job 1, './a.out' terminated by signal SIGSEGV (Address boundary error)