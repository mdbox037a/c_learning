#include <stdio.h>

int main() {
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n') // '' denotes a character constant, so returns value of that
                   // single character in machine character set
      ++nl;
  printf("%d\n", nl);
}
