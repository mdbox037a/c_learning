/* Exercise 2-10: Rewrite teh function lower, which converts upper case letters
 * to lower case, with a conditional expression instead if-else */

// original lower

int lower(int c) {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

// (hopefully) improved

int better_lower(int c) { return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; }
