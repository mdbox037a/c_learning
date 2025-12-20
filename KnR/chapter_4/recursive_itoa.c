/* Exercise 4-12: Adapt the ideas of printd() to write a recursive version of
 * itoa(); that is, convert an integer into a string by calling a recursive
 * routine */

#include <stdio.h>
#define MAX_STRING 100

char int_to_string(int number, char string[]);

int main() {
	int number;
	int scan_return;
	char string[MAX_STRING];

	while ((scan_return = scanf("Enter an integer: %d", &number)) != EOF) {
		int_to_string(number, string);
		printf("Your converted string: %s\n", string);
	}
	return 0;
}
