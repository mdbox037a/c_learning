/* Exercise 2-9: In a two's complement number system, x &= (x - 1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount */

// original bitcount()
// count 1's in x

int bitcount(unsigned x) {
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

// faster bitcount()
// "explain why"
/* x &= (x -1) always deletes the rightmost 1-bit because that bit has to be
 * "broken up" in order to create (x - 1).  Since (x - 1) must then have a 0
 * in that very position, once we AND with x, we guarantee a resulting 0 */

int faster_bitcount(unsigned x) {
	int b;
	for (b = 0; x != 0; x &= (x - 1))
		b++;
	return b;
}

/* this version only trimmed three lines of assembly, which doesn't seem like
 * much of a victory. but note that this version only loops the number of
 * times equal to the number of 1s in the number. the previous function will
 * loop once for every place in the number, 0 or 1, so the second function is
 * always faster, which the one exception of all 1s, where it ties. */
