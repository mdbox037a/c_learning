#include <stdio.h>

int main() {
  long nc;

  nc = 0;
  while (getchar() != EOF)
    ++nc; // ++nc and nc++ both increment, but have different values in
          // expressions
  printf("%ld\n", nc);
}
