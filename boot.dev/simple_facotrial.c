#include <stdio.h>

int main() {
	int n = 5;
	int result = 1;
	int i;

	for (i = 0; i < 5; i++) {
		result *= (i + 1);
	}

	printf("%d\n", result);
	return 0;
}
