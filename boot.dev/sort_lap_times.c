#include <stdio.h>

void sort_lap_times(int times[], int length) {
	int i, j, temp;

	for (i = 0; i < length - 1; i++) {
		for (j = 0; j < length - 1; j++) {
			if (times[j] > times[j + 1]) {
				temp = times[j + 1];
				times[j + 1] = times[j];
				times[j] = temp;
			}
		}
	}
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
