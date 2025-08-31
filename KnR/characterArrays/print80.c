#include <stdio.h>
#define MAXIMUM 1000
#define BAR 80

// TODO: need to alter logic to hold printing of 80+ lines until EOF
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
