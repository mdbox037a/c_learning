/* Exercise 3-2: Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies
 * th string t to s.  Use a switch.  Write a function for the other direction
 * as well, converting escape sequences into real characters */

#include <stdio.h>
#define MAX_STR_LEN 100

char escape(char c, char result[]);
char unescape(char c, char result[]);

int main() {
	// function to accept input and store in an array
	// then display the results
	char result[4], string[MAX_STR_LEN];
	int i, j, k, c, status;

	printf("Enter a string up to 99 characters long: ");
	for (int i = 0; (c = getchar()) != EOF && i < MAX_STR_LEN - 2;) {
		status = escape(c, result);
		if (status) {
			string[i++] = result[0];
			string[i++] = result[1];
		} else
			string[i++] = c;
	}
	// string[++i] = '\0';
	printf("\nYour string with escape characters displayed: %s\n", string);

	// clear string contents
	for (j = 0; j < MAX_STR_LEN - 1; ++j)
		string[j] = '\0';

	printf("Now enter a string with some written newlines and tabs: ");
	for (int k = 0; (c = getchar()) != EOF && k < MAX_STR_LEN - 1; ++k) {
		status = unescape(c, result);
		if (status)
			string[k] = result[0];
		else
			string[k] = c;
	}
	string[k] = '\0';
	printf("\nYour string with no escapes: %s\n", string);

	return 0;
}

char escape(char c, char result[4]) {
	switch (c) {
	case '\n':
		result[0] = '\\';
		result[1] = 'n';
		result[2] = '\0';
		return 1;
	case '\t':
		result[0] = '\\';
		result[1] = 't';
		result[2] = '\0';
		return 1;
	default:
		return 0;
	}
}

char unescape(char c, char result[4]) {
	// function to take a character from main() and if an escape character,
	// return \ such that the end text will display the \n or \t
	switch (c) {
	case '\\':
		result[0] = '\\';
		result[1] = '\0';
		return 1;
	default:
		return 0;
	}
}
