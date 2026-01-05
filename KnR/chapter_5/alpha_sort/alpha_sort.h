#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int my_getline(char *, int);
char *alloc(int);
void my_qsort(char *v[], int i, int j);
