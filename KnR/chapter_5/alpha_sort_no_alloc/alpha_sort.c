#include "alpha_sort.h"
#include <stdio.h>
#include <string.h>

char *lineptr[MAXLINES]; /* array of pointers to each line start */

/* sort input lines */
int main(void) {
	int nlines; /* number of input lines to read */
	char linestorage[MAXSTORAGE];

	if ((nlines = readlines(lineptr, linestorage, MAXLINES)) >= 0) {
		my_qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestorage, int maxlines) {
	int len, nlines;
	char *p = linestorage;
	char line[MAXLEN];
	char *linestop = linestorage + MAXSTORAGE;

	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || p + len > linestop)
			return -1;
		else {
			line[len - 1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}
