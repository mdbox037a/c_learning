/* Exercise 5-1: As written, getint() treats a + or - not followed by a digit
 * as a valid representation of zero. Fix it to push such a character back on
 * the input */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {
	int c, sign, extra;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		extra = c;
		if (!isdigit(c = getch())) {
			if (c != EOF)
				ungetch(c);
			ungetch(extra);
			return extra;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
