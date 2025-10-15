/* Exercise 3-3: Write a function expand(s1,s2) that expands shorthand
 * notations line a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2.  Allow for letters on either case and digits, and be
 * prepared to handle case like a-b-c and a-z0-9 and -a-z.  Arrange that a
 * leading or trailing - is taken literally */

#include <stdio.h>
#include <string.h>
#define MAX_S1_LEN 100
#define MAX_S2_LEN 1000

void expand(char s1[], char s2[]);

int main() {
	char s1[MAX_S1_LEN] = "test a-z test";
	char s2[MAX_S2_LEN];

	expand(s1, s2);
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
}

void expand(char s1[], char s2[]) {
	int c, i, j, k;
	char buffer[4] = {0};
	const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";
	const char *DIGITS = "0123456789";

	for (i = 1, j = 0; s1[i] != '\0' && j < MAX_S2_LEN - strlen(ALPHABET);
	     ++i) {
		if (s1[i - 1] == 'a' && s1[i] == '-' && s1[i + 1] == 'z') {
			for (k = 0; k < strlen(ALPHABET); ++k) {
				s2[j] = ALPHABET[k];
				++j;
			}
			i += 2; // jump ahead to get past the '-z'
		} else {
			s2[j] = s1[i - 1];
			++j;
		}
	}
	s2[j++] = s1[i - 1];
	s2[j] = '\0';
}
