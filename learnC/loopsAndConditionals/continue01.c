#include <stdio.h>

int main() {

	int i = 0;

	while (i < 10) {
		// Figure out how to skip the print of 5 here
		if (i == 5) {
			i++;
			continue;
		}

		printf("%d\n", i);
		i++;
	}
}
