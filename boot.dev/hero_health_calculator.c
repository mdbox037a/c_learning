#include <stdio.h>

int main() {
	int base_health = 120;
	int damage_per_hit = 15;
	int heal_amount = 20;

	int health_after_one_hit;
	int health_after_two_hits;
	int health_after_hit_and_heal;

	health_after_one_hit = base_health - damage_per_hit;
	health_after_two_hits = health_after_one_hit - damage_per_hit;
	health_after_hit_and_heal = health_after_one_hit + heal_amount;

	printf("%d\n", health_after_one_hit);
	printf("%d\n", health_after_two_hits);
	printf("%d\n", health_after_hit_and_heal);

	return 0;
}
