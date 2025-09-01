/* Exercise 1-18: Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank lines */

/* planning
 * get_line function with mods
 * - still receive input and cap wit \0
 * - if c == ' ' or '\t', NOP
 *
 * */

#include <stdio.h>
#define MAX_STRING_LEN 1000

int get_line(char line[], int max);
void trim_line(char line[], int len);

int main() {
	int len;
	char line[MAX_STRING_LEN];
	char trimmed[MAX_STRING_LEN];

	while ((len = get_line(line, MAX_STRING_LEN)) > 0) {
		trim_line(line, len);
		printf("%s\n", line);
	}

	return 0;
}

int get_line(char line[], int max) {
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void trim_line(char line[], int len) {
	int i = len - 1;
	while (line[i] == ' ' || line[i] == '\t') {
		line[i + 1] = '0';
		line[i] = '\0';
		--i;
	}
}
