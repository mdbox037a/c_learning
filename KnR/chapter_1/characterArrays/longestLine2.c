// TODO: fix logic here - something is very wrong
#include <stdint.h>
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[], int maxline);

/* print the longest input line;
 * exercise 1-16: revise the main routine so it will print the length of
 * arbitrarily long input lines, and as much as possible of the text */
int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line, MAXLINE);
		}
	if (max > 0) {
		printf("%s\n", longest);
		printf("That string was %d characters long\n", max);
	}
	return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim) {
	int c;
	int32_t i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
		++i;
	}
	if (c == '\n') { // one more round at newline
		s[i] = c;
		++i;
	}
	s[i] = '\0'; // place null character at end of array
	while ((c = getchar()) != EOF && c != '\n')
		++i;
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[], int lim) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0' && i < lim)
		++i;
}
