/* Exercise 1-18: Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank lines */

#include <stdio.h>
#define MAX_STRING_LEN 1000

int get_line(char line[], int max);
void trim_line(char line[], int len);

int main() {
	int len;
	char line[MAX_STRING_LEN];

	while ((len = get_line(line, MAX_STRING_LEN)) > 0) {
		printf("%s<--- end of original string\n", line);
		trim_line(line, len);
		printf("%s<--- end of trimmed string\n", line);
	}

	return 0;
}

int get_line(char line[], int max) {
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = '\0';
		//++i;
	}
	return i;
}

void trim_line(char line[], int len) {
	int i = len - 1;
	while (line[i] == ' ' || line[i] == '\t') {
		// line[i + 1] = '0';
		line[i] = '\0';
		--i;
	}
}
