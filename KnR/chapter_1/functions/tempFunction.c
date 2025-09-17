/* rewrite of previous temp conversion program to use functions */

#include <stdio.h>

int ftoc(int f);
int ctof(int c);

/* main function to test */
int main() {
	int i;
	int upper = 100;
	int lower = 0;
	int step = 10;

	printf("Fahrenheit to Celcius\n");
	for (i = lower; i <= upper; i = i + step)
		printf("%d %d\n", i, ftoc(i));
	printf("\n\n");

	printf("Celsius to Fahrenheit\n");
	for (i = lower; i <= upper; i = i + step)
		printf("%d %d\n", i, ctof(i));
	printf("\n");

	return 0;
}

/* function definitions */
int ftoc(int f) {
	int c;
	c = 5 * (f - 32) / 9;
	return c;
}

int ctof(int c) {
	int f;
	f = 9 * c / 5 + 32;
	return f;
}
