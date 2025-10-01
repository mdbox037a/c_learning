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
