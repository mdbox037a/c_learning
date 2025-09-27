/* Exercise 2-4: Write and alternative version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2 */

#include <stdio.h>

void anti_string(char s1[], char s2[]);

int main() {
	;
	// input and call function logic here
}

void anti_string(char s1[], char s2[]) {
	int i, j;

	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				s1[i] = s1[i + 1];
				// TODO: add logic to handle "s1: aa" case
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
