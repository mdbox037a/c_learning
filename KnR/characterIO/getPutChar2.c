#include <stdio.h>

/* copy input to output, version 2*/
int main() {
  int c;

  while ((c = getchar()) != EOF) // parentheses b/c != higher than =
    putchar(c);
}
