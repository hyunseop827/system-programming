/*
 * in Linux system, there are 3 types of timer. (<sys/time.h>)
 *
 * ITIMER_REAL: real time, gives SIGALRM signal when it's over.
 * ITIMER_VIRTUAL: check cpu time of process in user mode. gives SIGVTALRM
 * ITIMER_PROF: check the cpu time of process in user/system mode. gives SIGPROF signal.
 *
 */

/*
 * getitimer
 *
 * #include <sys/time.h>
 *
 * int getitimer(int which, struct itimerval *curr_value);
 *
 * which: timer type to search
 * curr_value: address of pointer to save the infos.
 *
 * struct itimerval {
 * 	struct timeval it_interval;
 * 	struct timeval it_value;
 * }
 *
 * struct timeval {
 * 	time_t tv_sec;
 * 	suseconds_t tv_usec;
 * }
 *
 */

/*
 * setitimer
 *
 * #include <sys/time.h>
 *
 * int setitimer(int which, const struct itimerval *value, struct itimerval *ovalue);
 *
 * which: type of timer
 * value: address of struct for timer set up.
 * ovalue: address of struct for the old timer set up.
 *
 */

#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler() {
	printf("timer invoked..\n");
}

int main() {
	struct itimerval it;

	signal(SIGALRM, sig_handler);

	it.it_value.tv_sec = 3;
	it.it_value.tv_usec = 0;
	it.it_interval.tv_sec = 2;
	it.it_interval.tv_usec = 0;

	if (setitimer(ITIMER_REAL, &it, (struct itimerval *)NULL) == -1){
		perror("setitimer");
		exit(1);
	}

	while(1){
		if (getitimer(ITIMER_REAL, &it) == -1){
			perror("getitimer");
			exit(1);
		}

		printf("%d sec, %d msec.\n", (int)it.it_value.tv_sec, (int)it.it_value.tv_usec);
		sleep(1);
	}

	return 0;
}

