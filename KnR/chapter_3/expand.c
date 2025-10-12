/* Exercise 3-3: Write a function expand(s1,s2) that expands shorthand
 * notations line a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2.  Allow for letters on either case and digits, and be
 * prepared to handle case like a-b-c and a-z0-9 and -a-z.  Arrange that a
 * leading or trailing - is taken literally */

#include <stdio.h>
#define MAX_STR_LEN 100
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

void expand(char s1[], char s2[]) { int c, i, j; }
