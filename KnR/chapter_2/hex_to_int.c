/* Exercise 2-3: Write a function htoi(s) which converts a string of hex
 * digits (including and optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 though 9, a through f, and A through F */

#include <stdio.h>

#define HEX_LEN 11

int htoi(int hex_array[]);

int main() {
	int hex_array[HEX_LEN] = "0x1f9b67dd";
	int result;

	result = htoi(hex_array);
	printf("original hex: %c\n", hex_array);
	printf("convert to int: %d\n", result);
	return 0;
}

int htoi(int hex_array[]) {
	int i, c;

	for (i = 0; i < HEX_LEN; ++i) {
		c = hex_array[i];
		if (c == 0 && i == 0)
			;
		else if (c == 'x' || c == 'X')
			;
		else {
			// insert conversoion logic here
		}
	}
}
