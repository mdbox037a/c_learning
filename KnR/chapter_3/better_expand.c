/* expand: expand shorthand notation in s1 into string s2 */
#include <stdio.h>
#define MAX_S1_LEN 50
#define MAX_S2_len 1000

void expand(char s1[], char s2[]);

int main() {
	int i, j, c;
	char s1[MAX_S1_LEN] = "test a-z test\0";
	char s2[MAX_S2_len];

	expand(s1, s2);
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);

	return 0;
}

void expand(char s1[], char s2[]) {
	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0')
		if (s1[i] == '-' && s1[i + 1] >= c) {
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		} else
			s2[j++] = c;
	s2[j] = '\0';
}

// TODO: create a main() function to input and test this
// TODO: see if the leading "-" would still trip up this solution
