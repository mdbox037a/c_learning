#include <stdio.h>

int main() {
	int baseFare = 120;
	int luggageFee = 30;
	int hasCoupon = 0;

	int totalBeforeDiscount;
	int finalTotal;

	totalBeforeDiscount = baseFare + luggageFee;
	if (hasCoupon)
		finalTotal = totalBeforeDiscount - 20;
	else
		finalTotal = totalBeforeDiscount;

	printf("%d\n", totalBeforeDiscount);
	printf("%d\n", finalTotal);

	return 0;
}
