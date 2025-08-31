#include <stdio.h>
#define MAXIMUM 1000
#define BAR 80

/* PLANNING
 * main()
 * - initialize array of MAXIMUM size
 * - call line_reader function(new_array, MAXIMUM)
 * - receive string from line_reader
 *   - if less than 80 chars, discard
 *   - if >= 80 chars, print it until \0
 * - call cleaner function
 *
 * line_reader function
 * - receive input
 * - store in an array up to MAXIMUM size
 * - place \0 at end of string
 * - return string_length
 *
 * cleaner function (maybe... I don't know how \0 works...)
 * - iterate over string and place 0 at each entry to \0, inclusive
 */

int line_reader(char line[], int max_length);

int main() {
	int string_length, i;
	char line[MAXIMUM];

	while ((string_length = line_reader(line, MAXIMUM)) > 0) {
		if (string_length >= BAR)
			printf("%s", line);
	}

	return 0;
}

int line_reader(char line[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}
