#include <limits.h>
#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* Exercise 2-6: Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving
 * the other bits unchanged */

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	return (x & ~((~(~0 << n)) << (p + 1 - n))) |
	       ((y & (~(~0 << n))) << (p + 1 - n));
}

/* Exercise 2-7: Write a function invert(x, p, n) that returns x with the n
 * bits that begin at position p inverted (i.e. 1 changed to 0 and vice versa)
 * leaving the others unchanged */

unsigned invert(unsigned x, int p, int n) {
	// return ((((x >> p) & (~(~0 << n))) ^ (~(~0 << n))) << p) |
	//       ((~((~(~0 << n)) << p)) & x);
	// obviously the above was bad, but is p here supposed to be left or
	// rightmost?

	return x ^ ((~(~0 << n)) << (p + 1 - n));
}

/* Exercise 2-8: Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n positions */

unsigned rightrot(unsigned x, int n) {
	// insert logic here
	for (int i = 0; i < n; ++i) {
		x = ((x & 1) << (sizeof(unsigned) * CHAR_BIT - 1)) | (x >> 1);
	}
	return x;
}
