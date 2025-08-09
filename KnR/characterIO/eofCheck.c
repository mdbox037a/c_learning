#include <stdio.h>

int c;
int check;

int main() {
  printf("hint: to kill this, press Ctrl-D\nEnter any text below:\n");
  printf("EOF value is: %i\n", EOF);

  while ((c = getchar()) != EOF) {
    printf("\n%i: ", check = (c != EOF));
    putchar(c);
  }
}
