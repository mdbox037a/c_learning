/* Exercise 4-13: Write a recursive version of reverse(s) which will reverse
 * the order of a string in-place */

#include <string.h>

void recursive_reverse(char string[], int left_index) {
	int right_index, character, string_length;
	right_index = string_length - left_index - 1;
	string_length = strlen(string);

	if (left_index < right_index) {
		character = string[left_index];
		string[left_index] = string[right_index];
		string[right_index] = character;
		recursive_reverse(string, ++left_index);
	}
}
