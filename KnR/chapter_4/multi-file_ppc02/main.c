#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100

int main() {
	int type;
	double op2;
	char s[MAXOP];

	// very cool - user input isn't into getch(), multiple levels down
	// the planning tree for this program; if it were me, I'd be trying
	// to get user input quickly, somewhere just below, but KnR aren't me
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop(); // because stack in wrong order for -
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			// .8 -> 8 decimal places; g -> shorter of f or e
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
