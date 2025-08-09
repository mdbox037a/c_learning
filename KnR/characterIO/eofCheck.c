#include <stdio.h>

int c;
int check;

int main() {
  while ((c = getchar()) != EOF) {
    putchar(c);
    printf("%i", check = (c != EOF));
  }
}
