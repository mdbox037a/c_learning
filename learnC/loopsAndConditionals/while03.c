#include <stdio.h>

int main() {

	int i = 9;
	int square = 0;

	// Write a while loop here:
	while (i >= 0) {
		square = i * i;
		printf("%d\t%d\n", i, square);
		i--;
	}
}
