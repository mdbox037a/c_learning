/* Exercise 4-12: Adapt the ideas of printd() to write a recursive version of
 * itoa(); that is, convert an integer into a string by calling a recursive
 * routine */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 100

void int_to_string(int number, char string[]);

int main() {
	int number;
	char string[MAX_STRING];

	printf("Enter an integer: ");
	while ((scanf("%d", &number)) == 1) {
		int_to_string(number, string);
		printf("Your converted string: %s\n\n", string);
		printf("Enter an integer: ");
	}
	return 0;
}

void int_to_string(int number, char string[]) {
	static int i;

	if (number / 10)
		int_to_string(number / 10, string);
	else {
		i = 0;
		if (number < 0)
			string[i++] = '-';
	}
	string[i++] = abs(number) % 10 + '0';
	string[i] = '\0';
}
