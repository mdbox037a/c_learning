/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-n] */
int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}

/* Exercise 3-1: Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with
 * only one test inside the loop and measure the difference in run-time */

int binsearch_v2(int x, int v[], int n) {
	int low, mid, high;

	low = 0;
	high = n - 1;
	// loop here
	return -1;
}
