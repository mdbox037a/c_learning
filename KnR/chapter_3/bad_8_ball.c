#include <stdio.h>

int main() {
	char c;

	printf("Think of your question, then enter a number from 1 to 8: ");
	while ((c = getchar()) != '\n') {
		// TODO: this setup allows a user to enter multiple numbers and
		// get multiple answers - fix
		switch (c) {
		case '1':
			printf("Sometimes good, sometimes shit\n");
			break;
		case '2':
			printf("Yes, it shall be\n");
			break;
		case '3':
			printf("Fortune favors the bold\n");
			break;
		case '4':
			printf("Good, good - do it\n");
			break;
		case '5':
			printf("No, not this time\n");
			break;
		case '6':
			printf("Not now, but when you least expect it, yes\n");
			break;
		case '7':
			printf("Never in a million years\n");
			break;
		case '8':
			printf("Even I am not powerful enough to know\n");
			break;
		default:
			printf("You have chosen poorly\n");
			break;
		}
	}
	return 0;
}
