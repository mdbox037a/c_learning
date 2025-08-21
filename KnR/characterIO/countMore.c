#include <stdio.h>

int main() {
  int c;
  int blanks = 0;
  int tabs = 0;
  int newlines = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++blanks;
    else if (c == '\t')
      ++tabs;
    else if (c == '\n')
      ++newlines;
    else
      ;
  }

  printf("%d blanks, %d tabs, %d newlines\n", blanks, tabs, newlines);
}
