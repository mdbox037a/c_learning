/* strlen: return length of string s */
int subtractive_strlen(char *s) {
	char *p = s;

	while (*p != '\0') // hit null terminator
		p++;
	return p - s; // get length by position - start
}
