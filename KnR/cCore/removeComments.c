/* Exercise 1-23: Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest */

#include <stdio.h>

int main() {
	int c;
	int i = 0;
	int in_comment = 0;

	char buffer[3];
	buffer[2] = '\0';

	while ((c = getchar()) != EOF && in_comment == 0) {
		if (i == 0) {
			buffer[0] = c;
			++i;
		} else if (i == 1) {
			buffer[1] = c;
			if (buffer[0] == '/' && buffer[1] == '*')
				in_comment = 1;
			else {
				printf("%c", buffer[0]);
				buffer[0] = buffer[1];
			}
		}
	}
}
