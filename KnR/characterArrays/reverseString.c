/* 1-19: write a function `reverse(s)` that reverses the character string
 * s.  Use it to write a program that reverses its input a line at a time */

#include <stdio.h>
#define MAX_STRING_LEN 1000

void reverse(char reverse_s, char s);

int main() {
	int c;
	int i = 0;
	char s[MAX_STRING_LEN];
	char reverse_s[MAX_STRING_LEN];

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			s[i] = c;
			++i;
			s[i] = '\0';
			reverse(reverse_s, s);
		} else {
			s[i] = c;
			++i;
		}
	}
}

void reverse(char reverse_s, char s) {}
