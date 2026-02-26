/*
 * assign handler in Solaris
 *
 * ch08-02.c is same as this but for solaris.
 */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo) {
	void (*hand)(int);

	hand = signal(SIGINT, sig_handler);

	if (hand == SIG_ERR) {
		perror("signal");
		exit(1);
	}

	printf("signal handler signal number: %d\n", signo);
	psignal(signo, "received signal");
}

int main() {
	void (*hand)(int);

	hand = signal(SIGINT, sig_handler);

	if(hand == SIG_ERR){
		perror("signal");
		exit(1);
	}

	printf("wait 1st Ctrl + C... : SIGINT\n");
	pause();

	printf("after 1st signal handler\n");
	printf("wait 2nd Ctrl + C... : SIGINT\n");
	pause();

	printf("after 2nd signal handler\n");

	return 0;
}

