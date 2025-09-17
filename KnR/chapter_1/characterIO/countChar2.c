#include <stdio.h>

int main() {
  double nc;

  for (nc = 0; getchar() != EOF; ++nc)
    ; // for requires a body, but all work done in the test and increment, so
      // add blank with ";"; called a null statement
  printf("%.0f\n", nc);
}
