/* Exercise 1-22: Write a program to fold long lines into two or more shorter
 * lines after the last non-blank character that occurs before the nth
 * column of input.  Make sure to do something intelligent with very long lines
 * and if there are no blanks or tabs before the specified column */

#include <stdio.h>

#define MAX_LEN 1000
#define LINE_BREAK 80

int get_line(char in_line[], int lim);
void prep_line(char out_line[], char in_line[]);

int main() {
	int i = 0;

	char in_line[MAX_LEN];
	char out_line[MAX_LEN];

	while ((get_line(in_line, MAX_LEN)) > 0) {
		prep_line(out_line, in_line);
		printf("%s\n", out_line);
		for (i = 0; i < MAX_LEN; ++i) {
			out_line[i] = '\0';
			in_line[i] = '\0';
		}
	}
}

int get_line(char in_line[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		in_line[i] = c;
	if (c == '\n') {
		in_line[i] = c;
		++i;
	}
	in_line[i] = '\0';
	return i;
}

void prep_line(char out_line[], char in_line[]) {
	int i = 0;
	int j = 0;
	int line_len = 0;
	int last_space = -1;

	while (in_line[i] != '\0') {
		out_line[j] = in_line[i];

		if (in_line[i] == ' ' || in_line[i] == '\t') {
			last_space = j;
		}

		if (line_len >= LINE_BREAK) {
			if (last_space != -1) {
				out_line[last_space] = '\n';
				line_len = j - last_space;
				last_space = -1;
			} else {
				// Word is longer than the line, so break it
				out_line[j + 1] = '\n';
				j++;
				line_len = 0;
			}
		}
		i++;
		j++;
		line_len++;
	}
	out_line[j] = '\0';
}
