/* Exercise 2-5: Write the function sny(s1, s2), which returns the first
 * location in a string s1 where any character from the string s2 occurs,
 * or -1 if s1 contains no characters from s2. */

#include <stdio.h>
#define MAX_STR_LEN 100

int any(char s1[], char s2[]);

int main() {
	// function to accept s1 and s2 input from user
	// call any() to filter and return
	int i, c, match;
	char s1[MAX_STR_LEN], s2[MAX_STR_LEN];

	printf("Enter a string: ");
	for (i = 0; (c = getchar()) != '\n' && i < MAX_STR_LEN - 1; ++i) {
		s1[i] = c;
	}
	printf("Enter a filter string: ");
	for (i = 0; (c = getchar()) != '\n' && i < MAX_STR_LEN - 1; ++i) {
		s2[i] = c;
	}

	match = any(s1, s2);
	printf("Location in s1 of first match: %d\n", match);

	return 0;
}

int any(char s1[], char s2[]) {
	// accept s1 and s2 from main() and filter by rules
	int i, j, c;
	for (i = 0; s1[i] != '\0'; ++i)
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j])
				return i;
	return -1;
}
