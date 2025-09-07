/* Exercise 1-22: Write a program to fold long lines into two or more shorter
 * lines after the last non-blank character that occurs before the nth
 * column of input.  Make sure to do something intelligent with very long lines
 * and if there are no blanks or tabs before the specified column */

#include <stdio.h>

#define MAX_LEN 1000
#define LINE_BREAK 80
#define IN 1
#define OUT 0

int get_line(char in_line[], int lim);
void prep_line(char out_line[], char in_line[]);

int main() {
	int i = 0;

	char in_line[MAX_LEN];
	char out_line[MAX_LEN];

	while ((get_line(in_line, MAX_LEN)) > 0) {
		prep_line(out_line, in_line);
		printf("%s\n", out_line);
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
	int j = i;
	int state = IN;
	int checkpoint = 0;

	for (i = 0; in_line[i] != '\0'; ++i) {
		if (state == OUT && (i % (LINE_BREAK - 1)) == 0) {
			out_line[j] = '\n';
			++j;
		}
		if (state == OUT && (in_line[i] == ' ' || in_line[i] == '\t')) {
			out_line[j] = in_line[i];
			checkpoint = j;
			++j;
		}
		if (state == OUT && in_line[i] != ' ' && in_line[i] != '\t') {
			state = IN;
			out_line[j] = in_line[i];
			++j;
		}
		if (state == IN && (i % (LINE_BREAK - 1)) == 0) {
			if (checkpoint > 0) {
				out_line[checkpoint] = '\n';
				++j;
			}
			if (checkpoint == 0) {
				out_line[j] = '\n';
				++j;
			}
		}
		if (state == IN && in_line[i] != ' ' && in_line[i] != '\t') {
			out_line[j] = in_line[i];
			++j;
		}
		if (state == IN && (in_line[i] == ' ' || in_line[i] == '\t')) {
			state = OUT;
			out_line[j] = in_line[i];
			checkpoint = j;
			++j;
		}
	}
	++j;
	out_line[j] = '\0';
}
