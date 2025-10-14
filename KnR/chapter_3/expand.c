/* Exercise 3-3: Write a function expand(s1,s2) that expands shorthand
 * notations line a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2.  Allow for letters on either case and digits, and be
 * prepared to handle case like a-b-c and a-z0-9 and -a-z.  Arrange that a
 * leading or trailing - is taken literally */

#include <stdio.h>
#define MAX_S1_LEN 100
#define MAX_S2_LEN 1000
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"

void expand(char s1[], char s2[]) {
	int c, i, j;
	char buffer[4] = {0};

	for (i = 1, j = 1; s1[i] != '\0' && j < MAX_S2_LEN - 2; ++i, ++j) {
		if (s1[i - 1] == 'a' && s1[i] == '-' && s1[i + 1] == 'z') {
			// TODO: figure out how to copy in multiple chars
			// starting from array position
			s2[j - 1] = ALPHABET;
		}
	}
}
