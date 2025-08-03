#include <stdio.h>

/* print fahrenheit to celsius table
 *   for fahr = 0, 20, ... 300 */

int main() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;   // lower limit of table
  upper = 300; // upper limit of table
  step = 20;   // amount to increase at each entry

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr += step;
  }
}
