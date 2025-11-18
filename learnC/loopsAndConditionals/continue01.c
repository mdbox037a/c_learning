#include <stdio.h>

int main() {

	int i;

	for (i = 0; i < 10; i++) {
		// Figure out how to skip the print of 5 here
		if (i == 5)
			continue;

		printf("%d\n", i);
	}
}
