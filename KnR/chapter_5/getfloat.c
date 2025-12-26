/* Exercise 5-2: Write getfloat(), the floating-point analog of getint().
 * What type does getfloat() return as its function value */

#include <ctype.h>
#include <math.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(float *pn) {
	int c, sign, places;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c) && c != '.'; c = getch())
		*pn = 10 * *pn + (c - '0');
	/* now handle fractional portion of number following . */
	for (places = 1; isdigit(c); c = getch(), places++)
		*pn = *pn + ((c - '0') * (pow(0.1, places)));
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
