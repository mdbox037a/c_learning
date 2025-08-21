#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c;
  int state;

  while ((c = getchar()) != EOF) {
    if (c == ' ' && state == IN) {
      state = OUT;
      printf(" ");
    } else if (c == ' ' && state == OUT)
      ;
    else {
      state = IN;
      putchar(c);
    }
  }
}
