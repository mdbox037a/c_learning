/* Exercise 1-24: Write a program to check a C program for rudimentary syntax
 * errors like unmatched parentheses, brackets, and braces.  Don't forget
 * about quotes, both single and double, escape sequences, and comments */

#include <stdio.h>
int characters[256];

void track_characters(int c);
void check_pairs();

int main() {
	int c, i, status;
	extern int characters[];

	while ((c = getchar()) != EOF) {
		track_characters(c);
	}
	check_pairs();

	// for (i = 0; i < 256; ++i) {
	//	printf("%c:%d\n", i, characters[i]);
	// }
	return 0;
}

void track_characters(int c) {
	extern int characters[];
	characters[c] += 1;
}

void check_pairs() {
	extern int characters[];
	if (characters['{'] != characters['}'])
		printf("unpaired '{' or '}'\n");
}

// TODO: initial POC for character-tracking array done; now need to compare
// results in array to determin unclosed brackets/parentheses/braces, etc.
