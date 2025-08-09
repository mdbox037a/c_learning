#include <stdio.h>

/*copy input to output,version 1*/
int main() {
  int c; // int to hold large enough values

  c = getchar();
  while (c != EOF) { // EOF is an integer defined in <stdio.h>
    putchar(c);
    c = getchar();
  }
}
