#include <stdio.h>

int main() {
	int slices_per_pizza = 8;
	int pizzas_ordered = 3;
	int extra_slices = 2;

	int total_slices = pizzas_ordered * slices_per_pizza + extra_slices;

	printf("%d\n", total_slices);

	return 0;
}
