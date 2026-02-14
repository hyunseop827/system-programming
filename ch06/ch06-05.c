/*
 * times
 *
 * store process launch time in tms. the unit is clock ticks.
 * returns -1 when it's failed.
 * time = user mode (from code) + system mode time (kernel, system calls)
 *
 * #include <sys/times.h>
 *
 * clock_t times(struct tms *buf);
 *
 * buf: address of buf.
 */


/*
 * struct tms {
 * 	clock_t tms_utime; // user mode run time
 * 	clock_t tms_stime; // system mode run time
 * 	clock_t tms_cutime; // process's all children' user mode run time
 * 	clock_t tms_cstime; // process's all chidren' system mode run time
 * }
 */

#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int i;
	time_t t;
	struct tms buf;
	clock_t ct,t1,t2;

	ct = sysconf(_SC_CLK_TCK);
	printf("Clock tick: %ld\n", ct);

	if ((t1 = times(&buf)) == -1){
		perror("times 1");
		exit(1);
	}

	for(i = 0 ; i < 999999999; i++)
		time(&t);
	sleep(1);

	if ((t2 = times(&buf)) == -1){
		perror("times 2");
		exit(1);
	}

	printf("t1: %ld\n", t1);
	printf("t2: %ld\n", t2);

	printf("utime: %ld\n", buf.tms_utime);
	printf("stime: %ld\n", buf.tms_stime);
	printf("Real time: %.1f sec\n", (double)(t2-t1) / ct);
	printf("User time: %.1f sec\n", (double)buf.tms_utime/ct);
	printf("System time: %.1f sec\n", (double)buf.tms_stime/ct);

	return 0;
}

