/*
 * pause
 *
 * #include <unistd.h>
 *
 * int pause(void);
 *
 * pause pauses process untill signal arrvies. it returns -1 when it gets signal.
 */

/*
 * sigpause
 *
 * #include <signal.h>
 *
 * int sigpause(int sigmask); // BSD
 * int sigpause(int sig); // System V
 *
 * sigmask: signal mask assigned to block and pause.
 * sig: signal to wait until other signal arrives.
 *
 * sigpause deletes mask and wait process until it gets new signal.
 */

/*
 * sigsuspend
 *
 * #include <signal.h>
 *
 * int sigsuspend(const sigset_t *mask);
 *
 * mask: address of signal set to wait.
 *
 * sigsuspend replaces signal sets and pause process until unblocked signals arrive.
 *
 */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_handler(int signo) {
	psignal(signo, "received signal:");
}

int main() {
	sigset_t set;

	signal(SIGALRM, sig_handler);

	sigfillset(&set);
	sigdelset(&set, SIGALRM);

	alarm(3);

	printf("wait... \n");

	sigsuspend(&set);

	return 0;
}

