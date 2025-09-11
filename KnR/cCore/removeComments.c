/* Exercise 1-23: Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest */

#include <stdio.h>

int print_buffer(char buffer[], int c, int in_comment);
int maybe_buffer(char buffer[], int c, int in_comment);
int hold_buffer(char buffer[], int c, int in_comment);

int main() {
	int c;
	int in_comment = 0;

	char buffer[3];
	buffer[0] = '\0';
	buffer[1] = '\0';
	buffer[2] = '\0';

	while ((c = getchar()) != EOF) {
		if (in_comment == 0)
			in_comment = print_buffer(buffer, c, in_comment);
		// had to assign function return value to in_comment
		// in order to have function local var by same name
		// get back "out" of the function. lol
		else if (in_comment == -1)
			in_comment = maybe_buffer(buffer, c, in_comment);
		else
			in_comment = hold_buffer(buffer, c, in_comment);
	}
}

int print_buffer(char buffer[], int c, int in_comment) {
	buffer[1] = c;
	if (buffer[0] == '/' && buffer[1] == '*')
		in_comment = 1;
	else if (buffer[1] == '/')
		in_comment = -1;
	else {
		// TODO: now the comment is almost all removed, except for the
		// first '/' --> need to figure this out
		printf("%c", buffer[1]);
		buffer[0] = buffer[1];
	}
	return in_comment;
}

int maybe_buffer(char buffer[], int c, int in_comment) {
	buffer[0] = buffer[1];
	buffer[1] = c;
	if (buffer[0] == '/' && buffer[1] == '*')
		in_comment = 1;
	else {
		in_comment = 0;
		printf("%c%c", buffer[0], buffer[1]);
	}
	return in_comment;
}

int hold_buffer(char buffer[], int c, int in_comment) {
	buffer[1] = c;
	if (buffer[0] == '*' && buffer[1] == '/')
		in_comment = 0;
	else
		buffer[0] = buffer[1];
	return in_comment;
}
