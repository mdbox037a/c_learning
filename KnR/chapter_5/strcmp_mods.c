/* compare two implementations of strcmp() for study */
/* strcmp: return <0 if s<t, 0 is s==t, >0 if s>t */
int index_strcmp(char *s, char *t) {
	int i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

int pointer_strcmp(char *s, char *t) {
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
