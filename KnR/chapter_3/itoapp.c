/* Exercise 3-4: In a two's complement number representation, or version of
 * itoa does not handle the largest negative number.  Explain why not.
 * Modify it to print that value correctly, regardless of the machine on
 * which it runs */

/* Explanation: In two's complement, there is only one zero, represented by
 * 00000000 (for example). So 100000000 isn't used for "negative zero",
 * instead it is used for one more negative number, -128 (or whatever).  Thus
 * when the previous version of -128 gets turned into +128, it overflows. */

#include <stdio.h>
#define MAX_LEN 100

int itoa(int n, char s[]);
void reverse(int len, char s[], char r[]);

int main() {
	int len, c, n;
	char s[MAX_LEN];
	char r[MAX_LEN];

	n = 123;
	len = itoa(n, s);
	printf("n: %d\n", n);
	printf("s: %s\n", s);

	reverse(len, s, r);
	printf("r: %s\n", r);

	return 0;
}

/* itoa: convert n to characters in s */
int itoa(int n, char s[]) {
	int i, sign;

	if ((sign = n) < 0) // record sign
		n = -n;     // make n positive
	i = 0;
	do {                           // generate digits in reverse order
		s[i++] = n % 10 + '0'; // get next digit
	} while ((n /= 10) > 0); // delete it
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
