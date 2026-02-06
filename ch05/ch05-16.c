/*
 * tzset
 *
 * tzset set time zone as where use locates.
 * it sets infos in external variables.
 *
 * extern char *tzname[2]; // time zone and corrected time zone in acroyms.
 * extern long timezone; // save time diffierence in second between UTC and local time.
 * extern int daylight; //if time zone has summer-time more than 0, else 0
 *
 */

#include <time.h>
#include <stdio.h>

int main() {
	tzset();

	printf("timezone: %d\n", (int)timezone);
	printf("daylight: %d\n", daylight);
	printf("TZname[0]: %s\n", tzname[0]);
	printf("TZname[1]: %s\n", tzname[1]);

	return 0;
}

