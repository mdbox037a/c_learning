/* power: raise base to nth power; n >= 0; version 2 */
#include <stdio.h>

int power(int base, int n);

int main() {
	int base = 2;
	int exponent = 10;
	int result;

	result = power(2, 10);

	printf("%d to the %dth power is %d\n", base, exponent, result);
}

int power(int base, int n) {
	int p;
	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}
