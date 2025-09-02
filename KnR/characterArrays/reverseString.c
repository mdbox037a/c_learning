/* 1-19: write a function `reverse(s)` that reverses the character string
 * s.  Use it to write a program that reverses its input a line at a time */

#include <stdio.h>
#define MAX_STRING_LEN 1000

void reverse(char reverse_s[], char s[], int i);

int main() {
	int c;
	int i = 0;
	char s[MAX_STRING_LEN];
	char reverse_s[MAX_STRING_LEN];

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			s[i] = '\0';
			reverse(reverse_s, s, i);
			printf("%s\n", reverse_s);
			i = 0;
		} else {
			s[i] = c;
			++i;
		}
	}
	return 0;
}

// TODO: fix the logic here so that the /0 stays at the end of the string
void reverse(char reverse_s[], char s[], int i) {
	int j = 0;

	for (i = i - 1; i >= 0; --i) {
		reverse_s[j] = s[i];
		++j;
	}
}
