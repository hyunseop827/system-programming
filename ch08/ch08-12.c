/*
 * sigprocmask
 *
 * #include <signal.h>
 *
 * int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
 *
 * how: blocking or no.
 * set: signal set's address to block.
 * oldset: NULL or previous signal set address.
 *
 * in `how`,
 * 	SIG_BLOCK: add signal mask to signal set.
 * 	SIG_UNBLOCK: delete signal mask from signal set.
 * 	SIG_SETMASK: substitute signal mask from original signal set.
 */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main() {
	sigset_t new;

	sigemptyset(&new);
	sigaddset(&new, SIGINT);
	sigaddset(&new, SIGQUIT);
	sigprocmask(SIG_BLOCK, &new, (sigset_t *)NULL);

	printf("Blocking signals: SIGINT, SIGQUIT\n");
	printf("send SIGQUIT\n");
	kill(getpid(), SIGQUIT);

	printf("unblocking signals\n");
	sigprocmask(SIG_UNBLOCK, &new, (sigset_t *)NULL);

	return 0;
}

