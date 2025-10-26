/* Exercise 3-6: Write a version of itoa that accepts 3 arguments instead
 * of two.  The third argument is a minimum filed width; the converted
 * number must be padded with blanks on the left if necessary to make it
 * wide enough */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

int itoa(int n, char s[], int w);
void reverse(int len, char s[], char r[]);

int main() {
	int len, c, n, w;
	char s[MAX_LEN];
	char r[MAX_LEN];

	n = 100;
	w = 16;
	len = itoa(n, s, w);
	printf("n: %d\n", n);
	printf("s: %s\n", s);
	printf("w: %d\n", w);

	reverse(len, s, r);
	printf("r: %s\n", r);

	return 0;
}

/* itoa: convert n to characters in s */
int itoa(int n, char s[], int w) {
	int i, sign, buffer;

	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while (abs(n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	// add field width buffer logic here
	while (i < w)
		s[i++] = ' ';
	// then terminate string
	s[i] = '\0';

	return i;
}

void reverse(int len, char s[], char r[]) {
	int i, j;
	for (i = 0, j = len - 1; i < len; i++, j--)
		r[j] = s[i];
	r[len] = '\0';
}
