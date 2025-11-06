#include <stdio.h>
#include <stdlib.h> // to get atof()

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0' // signal that a number was found

int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main() {
	int type;
	double op2;
	char s[MAXOP];

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
// NOTE: push(), and pop()

#define MAXVAL 100

/* sp and val-stack external b/c they need to be shared by push and pop */
int sp = 0;         // next free stack position
double val[MAXVAL]; // value stack

/* push: push f onto value stack */
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f; // store float at current pos., then ++
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
	if (sp > 0)
		return val[--sp]; // decrement first to get to last item
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

// NOTE: getop()

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]) {
	int i, c;

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
		ungetch(c);
	return NUMBER;
}

// NOTE: getch() and ungetch()

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;      // next free position in buf

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		bufp[bufp++] = c;
}
