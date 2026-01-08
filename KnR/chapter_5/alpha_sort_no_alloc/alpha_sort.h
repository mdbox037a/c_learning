#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTORAGE 5000

int readlines(char *lineptr[], char *linestorage, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int my_getline(char *, int);
void my_qsort(char *v[], int i, int j);
