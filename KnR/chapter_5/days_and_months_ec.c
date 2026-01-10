/* Exercise 5-8: There is no error checking in day_of_year or month_day.
 * Remedy this defect */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
	/* input validation */
	if (year < 0 || year > 99999 || month < 1 || month > 12 || day < 1 ||
	    day > 31) {
		printf("Invalid input, please try again");
		return -1;
	}

	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	/* check for day > num days in month */
	if (day > daytab[leap][month]) {
		printf("Invalid input, please try again");
		return -1;
	}

	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
	/* input validation */
	if (year < 0 || year > 99999 || yearday < 1 || yearday > 366) {
		printf("Invalid input, please try again");
		return;
	}

	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	/* check for yearday > num days in year */
	if (yearday > 365 + leap) {
		printf("Invalid input, please try again");
		return;
	}

	for (i = 1; yearday > daytab[leap][i]; i++)
		;
	yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
