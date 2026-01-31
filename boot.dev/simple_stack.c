#include <stdio.h>

#define STACK_CAPACITY 4

int stack[STACK_CAPACITY];
int top = -1;

int is_empty(void) { return 0; }

int is_full(void) { return 0; }

void push(int value) {}

int pop(void) { return 0; }

int main() {
	push(10);
	push(20);
	push(30);
	pop();
	push(40);
	push(50);
	push(60);

	int value = pop();
	printf("%d\n", value);

	while (!is_empty()) {
		printf("%d\n", pop());
	}

	return 0;
}
