/*
 * alarm
 *
 * #include <unistd.h>
 *
 * unsigned int alarm(unsiged int seconds);
 *
 * seconds: seconds until the alarm starts.
 *
 * only one alarm can be assigned to one process. 
 * if alarm is set before previous alarm starts, it replaces the old one.
 * if the seoncds is 0, all alarm will be canceled.
 * it will returns the remain time else it will return 0.
 *
 */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_handler(int signo) {
	psignal(signo, "received signal");
}

int main() {
	signal(SIGALRM, sig_handler);

	alarm(2);
	printf("wait...\n");

	sleep(3);

	return 0;
}

