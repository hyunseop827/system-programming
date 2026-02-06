/*
 * tm sturcture.
 *
 *
 * to save time infos in year, month, day. `tm` struct can be used.
 * it's written in `time.h`
 *
 * struct tm {
 * 	int tm_sec; // second.
 * 	int tm_min; // minute.
 * 	int tm_hour; // hour.
 * 	int tm_mday; // day.
 * 	int tm_mon; // month.
 * 	int tm_year; // year.
 * 	int tm_wday; // day (0 means Sunday, 6 means Saturday)
 * 	int tm_yday; // days (0 ~ 365)
 * 	int tm_isdst; // if time zone has summer time it's 1, else 0;
 * };
 */

/*
 * gmtime, localtime
 *
 * gmtime returns based on UTC, localtime returns based on local time zone.
 *
 * #include <time.h>
 * 
 * struct tm *gmtime(const time_t *timep);
 * struct tm *localtime(const time_t *timep);
 *
 * timep: address of time info in second.
 *
 */

#include <time.h>
#include <stdio.h>

int main() {
	struct tm *tm;
	time_t timep;

	time(&timep);
	printf("time(sec): %d\n", (int)timep);
	
	tm = gmtime(&timep);
	printf("GMTTIME=Y: %d", tm->tm_year);
	printf("M: %d",tm->tm_mon);
	printf("D: %d",tm->tm_mday);
	printf("H: %d",tm->tm_hour);
	printf("M: %d",tm->tm_min);
	printf("S: %d\n",tm->tm_sec);

	tm = localtime(&timep);

	printf("LOCALTIME= %d", tm->tm_year);

	printf("M: %d",tm->tm_mon);
	printf("D: %d",tm->tm_mday);
	printf("H: %d",tm->tm_hour);
	printf("M: %d",tm->tm_min);
	printf("S: %d\n",tm->tm_sec);

	return 0;
}

