/* Exercise 1-21: Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference? */

#include <stdio.h>

#define MAX_LEN 1000
#define TAB_LEN 4

int mod_line(line[]);

int main() {
	char line[];

	while ((mod_line(line)) > 0) {
		printf("%s", line);
	}
}

int mod_line(line[]) {
	int c, num_tabs, num_spaces, i;
	int space_counter = 0;

	for (i = 0; i < MAX_LEN - 1 && (c = getchar()) != EOF && c != '\n';) {
		if (c == ' ') {
			++space_counter;
		}
	}
}
