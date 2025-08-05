#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = -20;
  upper = 160;
  step = 20;

  printf("Cel. Fahr.\n============\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius * (9.0 / 5.0) + 32;
    printf("%4.0f %6.2f\n", celsius, fahr);
    celsius += step;
  }
}
