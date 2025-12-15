/* Exercise 4-10: An alternate organization uses getline() to read an entire
 * input line; this makes getch() and ungetch() unnecessary. Revise the
 * calculator to use this approach */

/* creating this copy to fully refactor getop() */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> // to get atof()
#include <string.h>

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0'
#define VARIABLE '1'
#define NUM_VARS 26

int getop(char s[]);
void push(double);
double pop(void);
void clear(void);
void ungets(char s[]);
int proto_getline(char s[], int lim);

int line_index = 0;
char line[MAXOP];

/* reverse Polish calculator */
int main() {
	int type, i;
	double op1, op2;
	char s[MAXOP];

	int vars[NUM_VARS];
	int values[NUM_VARS];
	for (i = 0; i < NUM_VARS; i++) {
		vars[i] = 0;
		values[i] = 0;
	}

	printf("commands: ? print top; & dup top; @ swap; $ clear stack\n");
	printf("math.h ops: ~ sine; E exp (Euler); ^ power\n");
	printf("variables - single, lower case letters only; = set; ! unset\n");
	printf("var z is special: always holds the last answer printed\n");
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
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '?':
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case '&':
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case '@':
			op1 = pop();
			op2 = pop();
			push(op1);
			push(op2);
			break;
		case '$':
			clear();
			break;
		case '~':
			// should there be error checking here? (1 arg only)
			push(sin(pop()));
			break;
		case 'E':
			push(exp(pop()));
			break;
		case '^':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case '\n':
			values['z' - 'a'] = op2 = pop();
			printf("\t%.8g\n", op2);
			// .8 -> 8 decimal places; g -> shorter of f or e
			break;
		case 'z':
			push(values['z' - 'a']);
			break;
		case '=':
			// set variable to value
			op2 = pop();
			op1 = pop();
			values[(char)op1 - 'a'] = op2;
			vars[(char)op1 - 'a'] = 1;
			push(op2);
			break;
		case '!':
			// unset variable by indicating non-value in tracking
			// array
			vars[(char)pop() - 'a'] = 0;
			push(0);
			break;
		default:
			if (islower(type)) {
				if (vars[type - 'a'] == 1)
					push(values[type - 'a']);
				else
					push(type);
				break;
			} else {
				printf("error: unknown command %s\n", s);
				break;
			}
		}
	}
	return 0;
}
// NOTE: push(), pop(), and clear()

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
		return val[--sp]; // decrement first to get previous item
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void clear(void) { sp = 0; }

// NOTE: getop()

int getop(char s[]) {
	int c, i;

	// NOTE: handle return to function ofter main() and terminate cleanly
	// or call proto_getline to get a new line b/c we don't have on yet
	if (line[line_index] == '\0') {
		if (proto_getline(line, MAXOP) == 0) {
			return EOF;
		} else {
			line_index = 0;
		}
	}
	/* skip over whitespace */
	while ((s[0] = c = line[line_index++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	// TODO: add handler for negative numbers
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	/* cycle through digits and store in s[] */
	if (isdigit(c))
		while (isdigit(s[++i] = c = line[line_index++]))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = line[line_index++]))
			;
	s[i] = '\0';
	line_index--;
	return NUMBER;
}

void ungets(char s[]) {
	int length = strlen(s);

	while (length > 0)
		ungetch(s[--length]);
}

/* getline: read a line into s, return length */
int proto_getline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
