/*
 * using `sysinfo()` write program that print run-time and convert it to hour:minutes format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() {
	struct sysinfo info;

	sysinfo(&info);

	long time_sec = info.uptime;

	printf("run-time: %ld seconds\n",time_sec);

	int hour = (time_sec / 60 ) / 60;
	int mintues = (time_sec / 60 );

	printf("run-time: %d : %d\n",hour,mintues);

	return 0;

}

