
/* Exercise 1-20: Write a program 'detab' that replaces tabs in the input with
 * the propoer number of blanks to space to the next tab stop.  Assume a fixed
 * set of tab stops, say every n columns.  Should n be a variable or a symbolic
 * parameter */

/* planning
 *
 * */

#include <stdio.h>
#define MAX_LEN 1000
#define TAB_SIZE 4

int get_line_detab(char line[]);

int main() {
	char line[MAX_LEN];

	while ((get_line_detab(line)) > 0)
		printf("%s\n", line);

	return 0;
}

int get_line_detab(char line[]) {
	int c, i, j;

	for (i = 0; i < MAX_LEN - 1 && (c = getchar()) != EOF && c != '\n';
	     ++i) {
		printf("%d", (TAB_SIZE - (i % TAB_SIZE)));
		if (c == '\t') {
			for (j = 0; j < (TAB_SIZE - (i % TAB_SIZE)); ++j) {
				line[i] = ' ';
				++i;
			}
		} else
			line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
