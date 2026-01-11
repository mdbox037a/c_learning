/* month_name: return name of the n-th month */
char *month_name(int n) {
	static char *name[] = {
	    "Illegal month", "January",  "February", "March",  "April",
	    "May",           "June",     "July",     "August", "September",
	    "October",       "November", "December"};

	return (n < 1 || n > 12) ? name[0] : name[n];
}

/* attempting to do the same as above - take up more space, but able to edit
 * months now? */
char *different_month_name(int n) {
	static char name[13][15] = {
	    "Illegal month", "January",  "February", "March",  "April",
	    "May",           "June",     "July",     "August", "September",
	    "October",       "November", "December"};

	return (n < 1 || n > 12) ? name[0] : name[n];
}
