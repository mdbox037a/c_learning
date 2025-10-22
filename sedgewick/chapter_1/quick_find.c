#include <stdio.h>
#define N 10

int main() {
	int i, p, q, t, id[N], x, y;

	for (i = 0; i < N; i++) // initialize array
		id[i] = i;
	printf("Input connections list:\n");
	while (scanf("%d %d", &p, &q) != EOF) {
		if (id[p] == id[q])
			continue;
		for (t = id[p], i = 0; i < N; i++)
			if (id[i] == t)
				id[i] = id[q];
		// printf(" %d %d\n", p, q);
	}
	clearerr(stdin);
	printf("Check connections:\n");
	while (scanf("%d %d", &x, &y) == 2) {
		if (id[x] == id[y])
			printf("Connection successful!\n");
		else
			printf("Connection unsuccessful...\n");
	}

	printf("Array contents:\n");
	for (i = 0; i < N; i++)
		printf("%d: %d\n", i, id[i]);
}
