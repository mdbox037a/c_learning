/* 13 - Roman to Integer: given a roman numeral, convert it to an integer */

int romanToInt(char *s) {
	/* planning:
	 * 1) create parallel array where each index holds integer equivalent
	 * of each char in s
	 * 2) find end of integer array and move towards beginning
	 * 3) add each integer to total, except if current index is less than
	 * previous index -> subtract in that case
	 * 4) return total */

	int i;
	int total = 0;
	int t[16];
	int sign = 1;

	for (i = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
		case 'I':
			t[i] = 1;
			break;
		case 'V':
			t[i] = 5;
			break;
		case 'X':
			t[i] = 10;
			break;
		case 'L':
			t[i] = 50;
			break;
		case 'C':
			t[i] = 100;
			break;
		case 'D':
			t[i] = 500;
			break;
		case 'M':
			t[i] = 1000;
			break;
		}
	}

	t[i] = 0;

	i = 0;
	while (t[i] != 0) {
		if (t[i] < t[i + 1])
			sign = -1;
		else
			sign = 1;
		total += t[i++] * sign;
	}

	return total;
}
