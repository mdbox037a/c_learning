#include <stdio.h>

// reviewing arrays from memory to check myself

int main() {

  // initialize multi-dimensional array
  int arr[4][2] = {{2, 1}, {3, 5}, {10, 11}, {12, 5}};

  int size;
  printf("%i\n", size = sizeof(arr));

  // loop through array and print all elements
  for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
    for (int j = 0; j < (sizeof(arr[0]) / sizeof(int)); j++) {
      printf("%i\n", arr[i][j]);
    }
  }
}
