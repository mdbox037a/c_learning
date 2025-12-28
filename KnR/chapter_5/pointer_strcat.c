/* Exercise 5-3: Write a pointer version of the function strcat() that we
 * showed in Chapter 2; strcat(s,t) copies the string t to the end of s */

/* Original strcat from chapter 2 */
/* strcat: concatenate t to end of s; s must be big enough */
void original_strcat(char s[], char t[]) {
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
}

/* New strcat() with pointer arithmetic implementation */
void pointer_strcat(char *s, char *t) {
	while (*s)
		*s++;
	while (*s++ = *t++)
		;
}
