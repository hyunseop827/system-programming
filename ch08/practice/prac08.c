/*
 *
 * using prac07 and re-write the SIGILL as default.
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo){
	printf("signal handler: %d\n", signo);
	psignal(signo, "received signal");

	signal(SIGILL, SIG_DFL);
}

int main() {
	void (*hand)(int);

	hand = signal(SIGILL, sig_handler);

	if (hand == SIG_ERR){
		perror("signal");
		exit(1);
	}

	kill(getpid(), SIGILL);
	kill(getpid(), SIGILL);

	return 0;
}

