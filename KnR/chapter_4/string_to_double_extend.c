#include <ctype.h>
#include <math.h>
#include <stdio.h>
#define MAX_LEN 21

// TODO: implement main() in order to compile and test

double atof(char s[]);

int main() {
	char s[MAX_LEN];
	double result;

	printf("Enter a number (max 20 chars): ");
	scanf("%s", s);
	result = atof(s);
	printf("%f\n", result);

	return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
	double val, power, e, esign, eval;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) // skip whitespace
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		esign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '-')
			i++;
		for (e = 1.0, eval = 0; isdigit(s[i]); i++) {
			eval *= e;
			eval = eval + (s[i] - '0');
			e *= 10;
		}
	}
	// NOTE: if e-n is greater than 6, double precision will not be enough
	return (sign * val / power) * (pow(10, (esign * eval)));
}
