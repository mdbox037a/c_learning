/* Exercise 2-3: Write a function htoi(s) which converts a string of hex
 * digits (including and optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 though 9, a through f, and A through F */

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define HEX_LEN 11

long htoi(char hex_array[]);

int main() {
	char hex_array[HEX_LEN];
	int i, c;
	long result;

	for (i = 0; i < HEX_LEN; ++i)
		hex_array[i] = '\0';

	printf("Enter a 4-byte hex number (0x optional): ");
	for (i = 0; (c = getchar()) != '\n' && i < HEX_LEN - 1; ++i)
		hex_array[i] = c;

	result = htoi(hex_array);
	if (result == -1)
		printf("Invalid Entry\n");
	else {
		printf("original hex: %s\n", hex_array);
		printf("convert to dec: %ld\n", result);
	}
	return 0;
}

long htoi(char hex_array[]) {
	int i, c, counter, base;
	long total, dec_value;
	counter = total = 0;
	base = 16;

	for (i = HEX_LEN - 2; i >= 0; --i) {
		c = hex_array[i];
		if (counter < 8) { // 8, as in, 4-bytes in hex
			if ('0' <= c && c <= '9') {
				dec_value = c - '0';
				++counter;
			} else if ('a' <= c && c <= 'f') {
				dec_value = c - 'a' + 10;
				++counter;
			} else if ('A' <= c && c <= 'F') {
				dec_value = c - 'A' + 10;
				++counter;
			} else if (c == '\0')
				;
			else
				return -1;
			total +=
			    dec_value * pow((double)base, (double)counter - 1);
		}
	}
	return total;
}
