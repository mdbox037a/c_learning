/* Exercise 3-5: Write the function itob(n,s,b) that converts the integer n
 * into a base b character representation in the string s. In particular,
 * itob(n,s,16) formats s as a hexadecimal integer in s. */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

int itob(int n, char s[], int b);
void reverse(int len, char s[], char r[]);

int main() {
	int len, c, n, b;
	char s[MAX_LEN];
	char r[MAX_LEN];

	n = 64;
	b = 2; // TODO: implement only bases 1, 2, 3, 8, 10, 12, and 16
	len = itob(n, s, b);
	printf("n: %d\n", n);
	printf("s: %s\n", s);
	printf("b: %d\n", b);

	reverse(len, s, r);
	printf("r: %s\n", r);

	return 0;
}

/* itob: convert n to characters in s, in base b */
// TODO: continue mods to have base flexibility
int itoa(int n, char s[], int b) {
	int i, sign;

	sign = n;
	i = 0;

	// for case b = 10:
	do {
		s[i++] = abs(n % 10) + '0';
	} while (abs(n /= 10) > 0);
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
