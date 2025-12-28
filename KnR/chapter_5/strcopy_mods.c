/* three versions of strcpy for comparison */
/* strcpy: copy t to s; array subscript version */
void subscript_strcpy(char *s, char *t) {
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

/* strcpy: copy t to s; pointer version */
void pointer_strcpy(char *s, char *t) {
	int i; // necessary?

	i = 0; // necessary?
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

/* strcpy: copy to to s; pointer version 3 */
void strcpy(char *s, char *t) {
	while (s++ = t++)
		;
}
