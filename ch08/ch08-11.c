/*
 * psignal
 *
 * #include <signal.h>
 *
 * void psignal(int sig, const char *s);
 *
 * sig: signal to print.
 * s: string to print.
 *
 * it prints out the string with signal as standard error/
 *
 */

/*
 * strsignal
 *
 * #include <string.h>
 *
 * char *strsignal(int sig);
 *
 * sig: signal to print out.
 *
 * it returns signal name as string. else it returns NULL
 *
 */

/*
 * sighold, sigrelse
 *
 * #include <signal.h>
 *
 * int sighold(int sig);
 * int sigrelse(int sig);
 *
 * sig: signal to block or release.
 *
 */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sig_handler(int signo) {
	char *s;

	s = strsignal(signo);
	printf("received signal: %s\n", s);
}

int main() {
	if (signal(SIGINT, sig_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}

	sighold(SIGINT);

	pause();

	exit(1);
}

