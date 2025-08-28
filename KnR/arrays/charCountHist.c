/* exercise 1-14: write a program to print a histogram of the frequencies of
 * different characters in its input */

#include <stdio.h>

int c, i, j, k, bars;
int char_array[256];

int main() {
	for (i = 0; i < 256; ++i)
		char_array[i] = 0;

	while ((c = getchar()) != '\n')
		++char_array[c];

	// v1 printer area

	// for (j = 0; j < 256; ++j) {
	// 	if (char_array[j] != 0)
	// 		printf("%c: %d\n", j, char_array[j]);
	// }

	// v2 printer area

	printf("=====Character Count Histogram=====\n");
	bars = 0;
	for (j = 0; j < 256; ++j) {
		if (char_array[j] != 0) {
			bars = char_array[j];
			printf("%3c: ", j);
			for (k = 0; k < bars; ++k)
				printf("|");
			printf("\n");
		}
	}
}
