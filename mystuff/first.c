#include <stdio.h>

int var1;
int var2;
int arr1[4] = {3, 10, 11, 5};

// display array contents

int main() {
  for (int i = 0; i < (sizeof(arr1) / sizeof(int)); i++) {
    printf("%i\n", arr1[i]);
  }
}

// random assignment testing

// var1
