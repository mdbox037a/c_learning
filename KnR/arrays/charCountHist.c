/* exercise 1-14: write a program to print a histogram of the frequencies of
 * different characters in its input */

#include <stdio.h>

int c, i, j, place;
int char_array[256];

int main() {
	for (i = 0; i < 256; ++i)
		char_array[i] = 0;

	while ((c = getchar()) != '\n')
		++char_array[c];

	// printer area

	for (j = 0; j < 256; ++j) {
		if (char_array[j] != 0)
			printf("%c: %d\n", j, char_array[j]);
	}
}
