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
	printf("----- power of two -----\n");
	int minpowerint, maxpowerint, previous, counter, base;
	base = 2;
	minpowerint = counter = 0;

	while (minpowerint >= 0) {
		++counter;
		minpowerint = calc_exp(base, counter);
	}
	printf("int bit size: %d, plus 1 sign bit\n", counter);
	printf("int min: %d\n", minpowerint);

	previous = maxpowerint = counter = 0;
	while (maxpowerint >= previous) {
		++counter;
		previous = maxpowerint;
		maxpowerint = calc_exp(base, counter) - 1;
	}
	printf("int max: %d\n", previous);

	return 0;
}

int calc_exp(int base, int power) {
	int result, i;
	result = base;

	if (power == 0) {
		return 1;
	} else {
		for (i = 1; i < power; ++i) {
			result *= base;
		}
		return result;
	}
}
