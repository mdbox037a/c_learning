#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int mini_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* find all lines matching a pattern */
int main() {
	char line[MAXLINE];
	int found = 0;
	int str_len = 0;

	// str_len = mini_getline(line, MAXLINE);
	while (mini_getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}

	return found;
}

/* getline: get line into s[], return length */
int mini_getline(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k;
	// TODO: implement right-start, using string length
	for (i = strlen(s) - 2; i != 0; i--) {
		for (j = i, k = (strlen(t) - 2); k != 0 && s[j] == t[k];
		     j--, k--)
			;
		if (k == 0)
			return i + 1; // TODO: this is dumb
	}
	return -1;
}
