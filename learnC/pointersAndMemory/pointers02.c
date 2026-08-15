#include <stdio.h>

int main() {

	double g = 9.95;
	double pi = 3.04;

	// Checkpoint 1 code goes here.
	double *dblPtr = &g;
	// Checkpoint 2 code goes here.
	printf("%p\n", dblPtr);
	// Checkpoint 3 code goes here.
	dblPtr = &pi;
}
