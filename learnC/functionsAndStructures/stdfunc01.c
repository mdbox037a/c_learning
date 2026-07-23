#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	// Write your code below
	int randNum = rand() % 20 + 1;

	printf("%d", randNum);
}
