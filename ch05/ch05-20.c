/*
 * asctime
 *
 * returns time info in string so user can read nice.
 *
 * #include <time.h>
 *
 * char *asctime(const struct tm *tm);
 *
 * tm: address of tm struct which contains time infos.
 *
 */

#include <time.h>
#include <stdio.h>

int main() {
	struct tm *tm;
	time_t timep;

	time(&timep);
	tm = localtime(&timep);

	printf("time(sec): %d\n", (int)timep);
	printf("time(date): %s", asctime(tm));

	return 0;
}

