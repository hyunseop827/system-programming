/*
 * ctime.
 *
 * print time in format for people to read comfortable.
 *
 * #include <time.h>
 *
 * char *ctime(const time_t *timep);
 *
 * timep: address of time info in sec.
 *
 */

#include <time.h>
#include <stdio.h>

int main() {
	time_t timep;

	time(&timep);

	printf("time(sec): %d\n", (int)timep);
	printf("time(date): %s", ctime(&timep));

	return 0;
}

