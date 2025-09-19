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

	return 0;
}
