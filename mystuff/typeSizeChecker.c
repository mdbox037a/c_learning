#include <stdio.h>

int main() {
  int size;
  printf("int size is: %i bytes\n", size = sizeof(int));
  printf("long size is: %i bytes\n", size = sizeof(long));
  printf("float size is: %i bytes\n", size = sizeof(float));
  printf("double size is: %i bytes\n", size = sizeof(double));
  printf("char size is: %i bytes\n", size = sizeof(char));
}
