#include <stdio.h>

#define NULL_INDEX -1

void print_list(int values[], int next_index[], int head_index) {}

int length_of_list(int next_index[], int head_index) {}

int sum_of_list(int values[], int next_index[], int head_index) {}

int main() {
	int values[5] = {10, 20, 30, 40, 50};
	int next_index[5] = {2, -1, 4, 0, 1};
	int head_index = 3;

	print_list(values, next_index, head_index);

	int len = length_of_list(next_index, head_index);
	printf("%d\n", len);

	int sum = sum_of_list(values, next_index, head_index);
	printf("%d\n", sum);

	return 0;
}
