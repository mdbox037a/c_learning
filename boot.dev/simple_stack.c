#include <stdio.h>

#define STACK_CAPACITY 4

int stack[STACK_CAPACITY];
int top = -1;

int is_empty(void) {
	if (top == -1)
		return 1;
	else
		return 0;
}

int is_full(void) {
	if (top == STACK_CAPACITY - 1)
		return 1;
	else
		return 0;
}

void push(int value) {
	if (is_full() == 0)
		stack[++top] = value;
}

int pop(void) {
	int value;
	if (is_empty() == 0) {
		value = stack[top--];
		return value;
	} else
		return -1;
}

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
