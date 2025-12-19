/* Exercise 4-11: Modify getop() so that is doesn't need to use ungetch()
 * Hint: use an internal static variable */

#include "calc.h"
#include <ctype.h>
#include <stdio.h>

int getop(char s[]) {
	int i, c;
	static int holder = 0;

	if (holder == 0)
		c = holder;
	else {
		c = getch();
		holder = 0;
	}
	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		holder = c;
	return NUMBER;
}
