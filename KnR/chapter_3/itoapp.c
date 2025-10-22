/* Exercise 3-4: In a two's complement number representation, or version of
 * itoa does not handle the largest negative number.  Explain why not.
 * Modify it to print that value correctly, regardless of the machine on
 * which it runs */

/* Explanation: In two's complement, there is only one zero, represented by
 * 00000000 (for example). So 100000000 isn't used for "negative zero",
 * instead it is the next lowest negative number, -128 (or whatever), which
 * has overflown. When -128 gets turned into +128:
 * 10000000 --> [invert] 01111111 --> [add 1] --> 10000000
 * it remains -128.  In my solution, I employ abs() to get around INT_MIN */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

int itoa(int n, char s[]);
void reverse(int len, char s[], char r[]);

int main() {
	int len, c, n;
	char s[MAX_LEN];
	char r[MAX_LEN];

	n = INT_MIN;
	len = itoa(n, s);
	printf("int min: %d\n", INT_MIN);
	printf("int max: %d\n", INT_MAX);
	printf("n: %d\n", n);
	printf("s: %s\n", s);

	reverse(len, s, r);
	printf("r: %s\n", r);

	return 0;
}

/* itoa: convert n to characters in s */
int itoa(int n, char s[]) {
	int i, sign;

	sign = n;
	i = 0;
	do {                                // generate digits in reverse order
		s[i++] = abs(n % 10) + '0'; // abs() to deal with negatives
	} while (abs(n /= 10) > 0); // delete one tens place
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	return i;
}

void reverse(int len, char s[], char r[]) {
	int i, j;
	for (i = 0, j = len - 1; i < len; i++, j--)
		r[j] = s[i];
	r[len] = '\0';
}
