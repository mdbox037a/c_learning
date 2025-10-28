#include <stdio.h>
#define MAXLINE 1000

int mini_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* find all lines matching a pattern */
int main() {
	char line[MAXLINE];
	int found = 0;

	while (mini_getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}

	return found;
}
