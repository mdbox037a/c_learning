/* Exercise 1-24: Write a program to check a C program for rudimentary syntax
 * errors like unmatched parentheses, brackets, and braces.  Don't forget
 * about quotes, both single and double, escape sequences, and comments */

#include <stdio.h>
#define BUFFERLEN 3
int characters[256];
char buffer[BUFFERLEN];

int track_characters(int c, int in_comment);
void check_pairs();

int main() {
	int c, i, status;
	int in_comment = 0;
	extern int characters[];
	extern char buffer[];

	for (i = 0; i < BUFFERLEN; ++i)
		buffer[i] = '\0';

	while ((c = getchar()) != EOF) {
		in_comment = track_characters(c, in_comment);
	}
	check_pairs();

	return 0;
}

int track_characters(int c, int in_comment) {
	extern int characters[];
	extern char buffer[];

	if (in_comment == 0) {
		buffer[1] = c;
		if (buffer[0] == '/' && buffer[1] == '*')
			in_comment = 1;
		else if (buffer[1] == '/')
			in_comment = -1;
		else {
			buffer[0] = buffer[1];
			characters[buffer[1]] += 1;
		}
		return in_comment;
	}

	if (in_comment == -1) {
		buffer[0] = buffer[1];
		buffer[1] = c;
		if (buffer[0] == '/' && buffer[1] == '*')
			in_comment = 1;
		else {
			in_comment = 0;
			characters[buffer[0]] += 1;
			characters[buffer[1]] += 1;
		}
		return in_comment;
	}

	if (in_comment == 1) {
		buffer[1] = c;
		if (buffer[0] == '*' && buffer[1] == '/')
			in_comment = 0;
		else
			buffer[0] = buffer[1];
		return in_comment;
	}
	return in_comment;
}

void check_pairs() {
	extern int characters[];
	if (characters['{'] != characters['}'])
		printf("unclosed '{}'\n");
	if (characters['('] != characters[')'])
		printf("unclosed '()'\n");
	if (characters['['] != characters[']'])
		printf("unclosed '[]'\n");
	if ((characters['"'] % 2) != 0)
		printf("unclosed double quotation marks\n");
	if ((characters['\''] % 2) != 0)
		printf("unclosed single quotations marks\n");
}

// TODO: implement escape character logic
