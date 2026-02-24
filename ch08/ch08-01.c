/*
 * kill
 *
 * kill function signal to process which has PID.
 * if signal is 0, it just checks error.
 *
 * #include <sys/types.h>
 * #include <signal.h>
 *
 * int kill(pid_t pid, int sig);
 *
 * pid_t pid: process's pid to get signal.
 * int sig: signal.
 *
 * if pid > 0 -> send signal to PID.
 * if pid < -1 -> send all signal to absolute number of PID.
 * if pid = 0 -> send signal to all process which has same group ID with PID.
 * if pid = -1 -> if user is not root, it sends all processes which user ID is same as sender ID
 */

/*
 * raise
 *
 * #include <signal.h>
 *
 * int raise(int sig);
 *
 * int sig: signal.
 *
 * raise sends signal to process which calls function `raise()`.
 * if signal handler was called, then raise doesn't return until it's done.
 * it returns 0 when it's successful, else it returns -1.
 */

/*
 * abort
 *
 * #include <stdlib.h>
 *
 * void abort(void);
 *
 * it sends `SIGABRT` signal to function which calls `abort()`.
 */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main() {
	printf("before SIGCONT signal to parent.\n");
	kill(getppid(), SIGCONT);

	printf("before SIGQUIT signal to me.\n");
	kill(getpid(), SIGQUIT);

	printf("after SIGQUIT signal.\n");

	return 0;
}

