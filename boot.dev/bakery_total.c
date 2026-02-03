#include <stdio.h>

int main() {
	int breadPrice = 3;
	int cakePrice = 7;
	int breadCount = 4;
	int cakeCount = 2;
	int breadTotal, cakeTotal, orderTotal;

	breadTotal = breadPrice * breadCount;
	cakeTotal = cakePrice * cakeCount;
	orderTotal = breadTotal + cakeTotal;

	printf("%d\n", breadTotal);
	printf("%d\n", cakeTotal);
	printf("%d\n", orderTotal);

	return 0;
}
