#include <stdio.h>

// Write your code below
void incrementAge(int *agePointer) { *agePointer += 1; }

int main(void) {
	int age = 37;
	incrementAge(&age);
	printf("%d\n", age);
}
