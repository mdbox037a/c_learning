/* Exercise 1-12: Write a program that prints its input one word per line*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, state;

  c = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      putchar('\n');
      putchar(c);
    } else
      putchar(c);
  }
}
