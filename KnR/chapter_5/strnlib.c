/* Exercise 5-5: Write versions of the libarary functions strncopy(), strncat()
 * and strncmp(), which operate on at most the first n characters of their
 * argument strings. */

#include <stdio.h>
#define MAX_LEN 80

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
void my_strncmp(char *s, char *t, int n);

int main(void) {
	char s[MAX_LEN];
	char t[MAX_LEN];
	int n;

	return 0;
}

/* strncpy(s,t,n): copy at most n characters of t to s; return s; pad with \0s
 * if t has fewer than n characters */
void my_strncpy(char *s, char *t, int n) { ; }

/* strncat(s,t,n): concatenate at most n characters of string t to s; terminate
 * s with \0; return s */
void my_strncat(char *s, char *t, int n) { ; }

/* strncmp(s,t,n): compare at most n characters of string s to string t;
 * return <0 if s<t, 0 if s==t, or >0 if s>t */
void my_strncmp(char *s, char *t, int n) { ; }
