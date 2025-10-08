/* Exercise 3-2: Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies
 * th string t to s.  Use a switch.  Write a function for the other direction
 * as well, converting escape sequences into real characters */

#include <stdio.h>

char escape(char c);
char unescape(char c);

int main() {
	// function to accept input and store in an array
	// then display the results
	return 0;
}

char escape(char c) {
	char result[3];
	// function to take a character from main() and if an escape
	// character, return visible characters (\t, \n)
	// planning: return result[] if escape character converted, 0 if not
	return 0;
}

char unescape(char c) {
	char result[4];
	// function to take a character from main() and if an escape character,
	// return \ such that the end text will display the \n or \t
	return 0;
}
