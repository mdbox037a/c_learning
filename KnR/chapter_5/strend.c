/* Exercise 5-4: Write the function strend(s,t), which returns 1 if the string
 * t occurs at the end of the string s, and zero otherwise */

int strend(char *s, char *t) {
	// NOTE: plan: find end of s, then decrement backwards until end of t
	// or divergence between t and s
	int result = 0;
	int s_counter = 1;
	int t_counter = 1;

	while (*s) {
		*s++;
		s_counter++;
	}
	while (*t) {
		*t++;
		t_counter++;
	}

	if (t_counter > s_counter)
		return result;

	while (*s-- == *t-- && t_counter > 0)
		;

	if (t_counter == 0) {
		result = 1;
		return result;
	} else
		return result;
}
