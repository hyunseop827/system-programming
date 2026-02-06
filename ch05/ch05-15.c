/*
 * gettimeofday
 *
 * returns time info in timeval struct.
 * `tz` is for time zone, yet doens't need to assign. NULL could be okay.
 * returns 0 when it's success, else returns -1.
 */

/*
 * timeval struct
 *
 * struct timeval {
 * 	time_t tv_sec; // second.
 * 	susecond_t tv_usec; // micro second.
 * };
 */

#include <sys/time.h>
#include <stdio.h>

int main() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	printf("time(sec): %d\n", (int)tv.tv_sec);
	printf("time(micro-sec): %d\n", (int)tv.tv_usec);

	return 0;
}

