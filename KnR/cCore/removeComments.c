/* Exercise 1-23: Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest */

#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		printf("%c", c);
	}
}
