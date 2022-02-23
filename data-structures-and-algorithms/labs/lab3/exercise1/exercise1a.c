#include <stdio.h>

char bits;

void printAddress(char *c) { printf("%u\n", c); }

void p() {
  char pilani;
  printAddress(&pilani);
}

void g() {
  char goa;
  printAddress(&goa);
}

void h() {
  char hyd;
  printAddress(&hyd);
}

void d() {
  char dub;
  printAddress(&dub);
}

int main() {
  p();
  g();
  h();
  d();
  printAddress(&bits);
  return 0;
}
