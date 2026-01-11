/* 9. Palindrome number: Given an integer x, return true if x is a palindrome,
 * and false otherwise. */
#include <stdbool.h>

bool isPalindrome(int x) {
	if (x < 0 || (x != 0 && x % 10 == 0))
		return false;
	if (x < 10)
		return true;

	int last_digit;
	int x_copy = x;
	long reversed_x = 0;

	while (x_copy > 0) {
		last_digit = x_copy % 10;
		reversed_x *= 10;
		reversed_x += last_digit;
		x_copy /= 10;
	}

	if (x == reversed_x)
		return true;
	return false;
}
