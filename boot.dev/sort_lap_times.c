#include <stdio.h>

void sort_lap_times(int times[], int length) {
	// your code here
}

int main() {
	int lap_times[] = {92, 105, 87, 99, 101, 93, 88};
	int length = sizeof(lap_times) / sizeof(lap_times[0]);

	sort_lap_times(lap_times, length);

	for (int i = 0; i < length; i++) {
		printf("%d\n", lap_times[i]);
	}

	return 0;
}
