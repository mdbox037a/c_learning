#include <stdio.h>

int main() {
	int baseGoal = 5000;
	int dailyIncrease = 500;
	int day, step_goal;

	for (day = 0; day < 7; day++) {
		step_goal = baseGoal + (dailyIncrease * day);
		printf("%d\n", step_goal);
	}

	return 0;
}
