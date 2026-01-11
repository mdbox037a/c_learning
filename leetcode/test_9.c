#include <stdio.h>
#include <stdbool.h>

// Forward declaration
bool isPalindrome(int x);

// Paste the user's function here for testing
bool isPalindrome(int x) {
	if (x < 0 || !(x % 10))
		return false;
	if (x < 10)
		return true;

	int last_digit;
	int reversed_x = 0;

	while (x > 0) {
		last_digit = x % 10;
		reversed_x *= 10;
		reversed_x += last_digit;
		x /= 10;
	}

	if (x == reversed_x)
		return true;
	return false;
}

int main() {
    int test_cases[] = {121, -121, 10, 0, 12321};
    int expected[] = {1, 0, 0, 1, 1};
    int n = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < n; i++) {
        bool result = isPalindrome(test_cases[i]);
        printf("Input: %d, Expected: %d, Got: %d -> %s\n", 
               test_cases[i], expected[i], result, 
               result == expected[i] ? "PASS" : "FAIL");
    }
    return 0;
}
