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
		printf("unclosed '{}'\n");
	if (characters['('] != characters[')'])
		printf("unclosed '()'\n");
	if (characters['['] != characters[']'])
		printf("unclosed '[]'\n");
}

// TODO: complete logic for "" and ''
// TODO: begin plan for escape sequences and comments linting
