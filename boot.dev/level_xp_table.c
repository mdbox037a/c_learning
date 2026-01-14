#include <stdio.h>

int main() {
	int base_xp = 100;
	int level;
	int xp;

	for (level = 1; level <= 5; level++) {
		xp = level * base_xp;
		printf("%d %d\n", level, xp);
	}

	return 0;
}
