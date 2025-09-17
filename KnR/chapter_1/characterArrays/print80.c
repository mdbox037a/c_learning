#include <stdio.h>
#define MAX_ARRAY_SIZE 1000
#define MAX_NUM_ARRAYS 50
#define BAR 80

// TODO: need to alter logic to hold printing of 80+ lines until EOF

/* planning logic changes
 * if string_length >= 80, create a new array and copy string there
 * keep track of string names in another array
 * then iterate over string array and print at end
 * */

int line_reader(char line[], int max_length);
void copy(char to[], char from[]);

int main() {
	int string_length, i, j, k, current_array;
	char line[MAX_ARRAY_SIZE];
	// implement a 'saver' array of 80+ char arrays
	char size80_arrays[MAX_NUM_ARRAYS][MAX_ARRAY_SIZE];

	current_array = 0;
	// set all values in multD array to 0; not sure this is necessry tho...
	for (j = 0; j < MAX_NUM_ARRAYS; ++j)
		for (k = 0; k < MAX_ARRAY_SIZE; ++k)
			size80_arrays[j][k] = 0;

	while ((string_length = line_reader(line, MAX_ARRAY_SIZE)) > 0) {
		if (string_length >= BAR) {
			copy(size80_arrays[current_array], line);
			++current_array; // get set for next array in multD
			                 // array
		}
	}

	// printout all 80+ char arrays
	for (i = 0; i <= current_array; ++i) {
		printf("%s\n", size80_arrays[i]);
		// TODO: prettyfy this output?
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

void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
