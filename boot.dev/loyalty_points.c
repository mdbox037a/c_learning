#include <stdio.h>

int main() {
	int cups_bought = 7;
	int points_per_cup = 12;
	int bonus = 30;
	int base_points, total_points;

	base_points = cups_bought * points_per_cup;
	total_points = base_points + bonus;

	printf("%d\n", cups_bought);
	printf("%d\n", base_points);
	printf("%d\n", total_points);

	return 0;
}
