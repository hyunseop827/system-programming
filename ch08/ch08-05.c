/*
 * signal set 
 *
 * each bit is related to signal.
 *
 * signal_t struct
 *
 * in LINUX.
 *
 * typedef struct {
 * 	unsigned long __val[_NISG_WORDS];
 * } stigset_t
 *
 * in Solaris.
 *
 * typedef sturct {
 * 	unisged int __sigbits[4];
 * } sigset_t
 *
 */

/*
 * sigemptyset
 *
 * #include <signal.h>
 *
 * int sigemptyset(sigset_t *set);
 * set: address of sigset to empty.
 *
 * it emptys set's bits as 0. returns 0 when it's successful, else -1
 *
 */

/*
 * sigfillset
 *
 * #include <signal.h>
 *
 * int sigfillset(sigset_t *set);
 *
 * set: address of sigset to set.
 *
 * it makes all the bits in set as 1. returns 0 when it's successful, else return 0.
 *
 */

/*
 * sigaddset
 *
 * #include <signal.h>
 *
 * int sigaddset(sigset_t *set, int signum);
 *
 * set: address of sigset to set.
 * signum: signal to add in set.
 *
 * it adds `signum` to `set`, returns 0 when it's successful, else returns -1.
 *
 */

/*
 * sigdelset
 *
 * #include <signal.h>
 *
 * int sigdelset(sigset_t *set, int signum);
 *
 * set: address of set.
 * signum: signum to delete.
 *
 * it delets `signum` from set. returns 0 when it's successful, else returns -1.
 *
 */

/*
 * sigismember
 *
 * #include <signal.h>
 *
 * int sigismember(const sigset_t *set, int signum);
 *
 * set: address of set.
 * signum: signum to check.
 *
 * it checks if `signum` is in set. returns 0 when it's successful, else returns -1.
 *
 */

#include <signal.h>
#include <stdio.h>

int main() {
	sigset_t st;

	sigemptyset(&st);

	sigaddset(&st, SIGINT);
	sigaddset(&st, SIGQUIT);

	if(sigismember(&st, SIGINT))
		printf("SIGINT has been set.\n");

	printf("** bit pattern: %lx\n", st.__val[0]);

	return 0;
}

