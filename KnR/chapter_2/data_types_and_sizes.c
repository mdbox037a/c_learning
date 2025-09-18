/* Exercise 2-1: write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Also try float and double */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
	char character;
	short shorty;
	int integer;
	long longy;

	printf("a char is between %d and %d\n", CHAR_MIN, CHAR_MAX);

	return 0;
}
