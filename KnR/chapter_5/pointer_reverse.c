/* Exercise 5-6: Rewrite reverse() from chapter 3 with pointers instead of
 * array indexing */

#include <string.h>

/* Original chapter3 reverse() */
void ch3_reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j++) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* ch5_reverse: use pointer arithmetic to reverse the characters of a string
 * in-place */
