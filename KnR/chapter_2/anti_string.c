/* Exercise 2-4: Write and alternative version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2 */

#include <stdio.h>
#define MAX_STR_LEN 100

void anti_string(char s1[], char s2[]);

int main() {
	char c, s1[MAX_STR_LEN], s2[MAX_STR_LEN];
	int i;

	printf("Input original string: ");
	for (i = 0; (c = getchar()) != '\n' && i < MAX_STR_LEN - 1; ++i) {
		s1[i] = c;
	}
	s1[++i] = '\0';

	printf("Input filter string: ");
	for (i = 0; (c = getchar()) != '\n' && i < MAX_STR_LEN - 1; ++i) {
		s2[i] = c;
	}
	s2[++i] = '\0';

	anti_string(s1, s2);
	printf("Resulting string: %s\n", s1);
	return 0;
}

void anti_string(char s1[], char s2[]) {
	int i, j;

	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				s1[i] = '\a';
				// TODO: implement a less duct tapey solution
			}
		}
	}
}

// original squeeze from KnR:

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
