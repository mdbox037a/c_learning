#include <stdio.h>

int main() {
	char c;

	printf("Think of your question, then enter a number from 1 to 8: ");
	while ((c = getchar()) != '\n')
		;

	switch (c) {
	case '1':
		printf("Sometimes good, sometimes shit\n");
	case '2':
		printf("Yes, it shall be\n");
	case '3':
		printf("Fortune favors the bold\n");
	case '4':
		printf("Good, good - do it\n");
	case '5':
		printf("No, not this time\n");
	case '6':
		printf("Not now, but when you least expect it, yes\n");
	case '7':
		printf("Never in a million years\n");
	case '8':
		printf("Even I am not powerful enough to know\n");
	default:
		printf("You have chosen poorly\n");
	}
	return 0;
}
