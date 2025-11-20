#include <stdio.h>

int main() {

	double g = 9.81;
	double pi = 3.14;

	// Checkpoint 1 code goes here.
	double *dblPtr = &g;
	// Checkpoint 2 code goes here.
	printf("%p", dblPtr);
	// Checkpoint 3 code goes here.
	dblPtr = &pi;
}
