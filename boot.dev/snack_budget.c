#include <stdio.h>

int main() {
	int budget = 500;
	int popcornCost = 120;
	int drinkCost = 80;
	int remainingBudget;

	remainingBudget = budget - ((1 * popcornCost) + (2 * drinkCost));

	printf("%d\n", budget);
	printf("%d\n", remainingBudget);
	return 0;
}
