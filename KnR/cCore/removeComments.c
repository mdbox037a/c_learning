/* Exercise 1-23: Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest */

#include <stdio.h>

int in_comment;

int print_buffer(char buffer[], int c, int in_comment);
int hold_buffer(char buffer[], int c, int in_comment);

int main() {
	int c;
	extern int in_comment;
	in_comment = 0;

	char buffer[3];
	buffer[0] = '\0';
	buffer[1] = '\0';
	buffer[2] = '\0';

	while ((c = getchar()) != EOF) {
		if (in_comment == 0)
			print_buffer(buffer, c, in_comment);
		else
			hold_buffer(buffer, c, in_comment);
	}
}

int print_buffer(char buffer[], int c, int in_comment) {
	buffer[1] = c;
	if (buffer[0] == '/' && buffer[1] == '*')
		in_comment = 1;
	else {
		printf("%c", buffer[1]);
		buffer[0] = buffer[1];
	}
	return in_comment;
}

int hold_buffer(char buffer[], int c, int in_comment) {
	buffer[1] = c;
	// TODO: understand if perhaps the ordering here is breaking out of the
	// function too soon
	if (buffer[0] == '*' && buffer[1] == '/')
		in_comment = 0;
	else
		buffer[0] = buffer[1];
	return in_comment;
}
