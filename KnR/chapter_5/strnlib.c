/* Exercise 5-5: Write versions of the libarary functions strncopy(), strncat()
 * and strncmp(), which operate on at most the first n characters of their
 * argument strings. */

#include <stdio.h>
#include <string.h>
#define MAX_LEN 80

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main(void) {
	char s[MAX_LEN];
	char t[MAX_LEN];
	int n, result;

	/* test my_strncpy; expected result: "test thing" */
	strcpy(s, "best thing");
	strcpy(t, "test bring");
	n = 4;
	my_strncpy(s, t, n);
	printf("%s\n", s);

	/* test my_strncat; expected result: "best thing string"*/
	strcpy(s, "best thing");
	strcpy(t, " string bean");
	n = 7;
	my_strncat(s, t, n);
	printf("%s\n", s);

	/* test my_strncmp; expected result: 0, then 8 */
	strcpy(s, "best thing");
	strcpy(t, "best thang");
	n = 7;
	result = my_strncmp(s, t, n);
	printf("%d\n", result);
	n = 8;
	result = my_strncmp(s, t, n);
	printf("%d\n", result);

	return 0;
}

/* strncpy(s,t,n): copy at most n characters of t to s; return s; pad with \0s
 * if t has fewer than n characters */
void my_strncpy(char *s, char *t, int n) {
	while (n > 0) {
		if (*t != '\0')
			*s++ = *t++;
		else
			*s++ = '\0';
		n--;
	}
}

/* strncat(s,t,n): concatenate at most n characters of string t to s; terminate
 * s with \0; return s */
void my_strncat(char *s, char *t, int n) {
	while (*s)
		*s++;
	while (n > 0) {
		if (*t != '\0')
			*s++ = *t++;
		else
			*s++ = '\0';
		n--;
	}
}

/* strncmp(s,t,n): compare at most n characters of string s to string t;
 * return <0 if s<t, 0 if s==t, or >0 if s>t */
int my_strncmp(char *s, char *t, int n) {
	while (n > 0) {
		if (*s == '\0' || *t == '\0') {
			return *s - *t;
		} else {
			if (*s == *t) {
				*s++;
				*t++;
				n--;
			} else {
				return *s - *t;
			}
		}
	}
	return 0;
}
