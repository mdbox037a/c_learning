/* Exercise 1-24: Write a program to check a C program for rudimentary syntax
 * errors like unmatched parentheses, brackets, and braces.  Don't forget
 * about quotes, both single and double, escape sequences, and comments */

#include <stdio.h>
int characters[256];

int track_characters(int c);

int main() {
	int c, i, status;
	extern int characters[];

	while ((c = getchar()) != EOF) {
		status = track_characters(c);
	}

	for (i = 0; i < 256; ++i) {
		printf("%c:%d\n", i, characters[i]);
	}
}

int track_characters(int c) {
	extern int characters[];
	characters[c] += 1;
	return 0;
}

// TODO: initial POC for character-tracking array done; now need to compare
// results in array to determin unclosed brackets/parentheses/braces, etc.
