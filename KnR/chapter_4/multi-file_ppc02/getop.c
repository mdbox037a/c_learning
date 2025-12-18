/* Exercise 4-11: Modify getop() so that is doesn't need to use ungetch()
 * Hint: use an internal static variable */

#include "calc.h"
#include <ctype.h>
#include <stdio.h>

static char holder;

int getop(char s[]) {
	int i, c;

	// TODO: add check for contents of holder
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
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
