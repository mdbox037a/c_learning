/* Exercise 2-3: Write a function htoi(s) which converts a string of hex
 * digits (including and optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 though 9, a through f, and A through F */

#include <math.h>
#include <stdio.h>

#define HEX_LEN 11

int htoi(char hex_array[]);

int main() {
	char hex_array[HEX_LEN] = "0x1f9b67dd";
	int result;

	result = htoi(hex_array);
	printf("original hex: %s\n", hex_array);
	printf("convert to int: %d\n", result);
	return 0;
}

int htoi(char hex_array[]) {
	int i, c, counter, base, dec_value, total;
	counter = total = 0;
	base = 16;

	for (i = HEX_LEN - 2; i >= 0; --i) {
		c = hex_array[i];
		// printf("c: %c\n", c);
		if (c == 0 && i == 0)
			;
		else if (c == 'x' || c == 'X')
			;
		else {
			if ('0' <= c && c <= '9')
				dec_value = c - '0';
			else if ('a' <= c && c <= 'f')
				dec_value = c - 'a' + 10;
			else if ('A' <= c && c <= 'F')
				dec_value = c - 'A' + 10;
			else
				return -1;
			total += dec_value * pow((double)base, (double)counter);
			// printf("total: %d\n", total);
			++counter;
		}
	}
	return total;
}
