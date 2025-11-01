#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]) {
	double val, power, e, esign;
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
	// TODO: implement scientific notation handler
	// PLANNING: construct multiplier with correct number of zeroes
	// PLANNING: then tack on to original return
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		esign = (s[i] == '-')
		            ? -1
		            : 1; // TODO: actually, maybe something smarter like
		                 // * or /, depending on sign...
		for (e = 1.0; isdigit(s[i]); i++) {
			// TODO: implement logic
			;
		}
	}
	return sign * val / power;
}
