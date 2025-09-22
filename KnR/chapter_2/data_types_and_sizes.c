/* Exercise 2-1: write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Also try float and double */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int calc_exp(int base, int power);

int main() {

	printf("##### from macros #####\n");
	printf("----- signed int/char types -----\n");
	printf("char: %d to %d bits\n", CHAR_MIN, CHAR_MAX);
	printf("signed char: %d to %d bits\n", SCHAR_MIN, SCHAR_MAX);
	printf("short: %d to %d bits\n", SHRT_MIN, SHRT_MAX);
	printf("int: %d to %d bits\n", INT_MIN, INT_MAX);
	printf("long: %ld to %ld bits\n", LONG_MIN, LONG_MAX);
	printf("----- unsigned int/char types -----\n");
	printf("uchar: %d\n", UCHAR_MAX);
	printf("ushort: %d\n", USHRT_MAX);
	printf("uint: %d\n", UINT_MAX);
	printf("ulong: %ld\n", ULONG_MAX);
	printf("\n");

	printf("##### computed values #####\n");

	// underflow/overflow char
	printf("----- underflow/overflow -----");
	char minchar, maxchar;
	minchar = maxchar = 0;
	for (minchar = 0; minchar >= 0; ++minchar)
		;
	for (maxchar = 0; maxchar <= 0; --maxchar)
		;
	printf("char: %d to %d bits\n", minchar, maxchar);

	// power of two method
	printf("----- power of two -----");
	char minpowerchar, maxpowerchar;
	int i, previous;
	minpowerchar = maxpowerchar = previous = 1;
	// TODO: construct power exponent loop to double char until over/under

	printf("char min: %d\n", minpowerchar);

	return 0;
}

int calc_exp(int base, int power) {
	int result, base, power;

	if (power == 0) {
		return 1;
	}

	for (i = 1; i < power; ++i) {
		result *= base;
	}
}
