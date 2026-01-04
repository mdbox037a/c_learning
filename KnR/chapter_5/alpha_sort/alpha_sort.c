#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES]; /* array of pointers to each line start */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
