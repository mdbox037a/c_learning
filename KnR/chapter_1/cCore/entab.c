/* Exercise 1-21: Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference? */

#include <stdio.h>

#define MAX_LEN 1000
#define TAB_LEN 4
#define IN 1
#define OUT 0

int mod_line(char line[]);

int main() {
	char line[MAX_LEN];

	while ((mod_line(line)) > 0) {
		printf("%s\n", line);
	}
}

int mod_line(char line[]) {
	int c, i, j, k;
	int space_counter = 0;
	int state = IN;

	for (i = 0; i < MAX_LEN - 1 && (c = getchar()) != EOF && c != '\n';) {
		if (c == ' ') {
			if (state == IN) {
				state = OUT;
				space_counter = 0;
				++space_counter;
			}
			if (state == OUT)
				++space_counter;
		}
		if (c != ' ') {
			if (state == IN) {
				line[i] = c;
				++i;
			}
			if (state == OUT) {
				state = IN;
				// entab logic here
				// starting tabs
				for (j = 0; j < space_counter / TAB_LEN; ++j) {
					line[i] = '\t';
					++i;
				}
				// ending spaces
				// TODO: determine why this needs to be j = 1
				for (j = 1; j < space_counter % TAB_LEN; ++j) {
					line[i] = ' ';
					++i;
				}
				line[i] = c;
				++i;
			}
		}
	}
	if (state == OUT) {
		for (j = 0; j < space_counter; ++j) {
			line[i] = ' ';
			++i;
		}
		line[i] = '\0';
	}
	if (state == IN)
		line[i] = '\0';
	return i;
}
