/*
 * sigset
 *
 * #include <signal.h>
 *
 * sighandler_t sigset(int sig, sighandler_t disp);
 *
 * sig: signal to process.
 * disp: sighandler's name.
 *
 * sigset has same struct as signal()
 *
 * sigset's first argument also can be anything except SIGKILL and SIGSTOP.
 * second argument also can be either adress of function or SIG_IGN, SIG_DFL.
 *
 * it returns SIG_ERR when it's failed.
 *
 * sigset isn't recommanded in LINUX, in Solaris sigset() is different that it assign handler again unlike signal().
 *
 */

// in Solaris..

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo) {
	printf("signal handler signal number: %d\n", signo);
	psignal(signo, "received signal");
}

int main() {
	void (*hand)(int);

	hand = sigset(SIGINT, sig_handler);

	if (hand == SIG_ERR){
		perror("signal");
		exit(1);
	}

	printf("wait 1st Ctrl+C ... : SIGINT\n");
	pause();

	printf("after 1st signal handler\n");
	printf("wait 2nd Ctrl+C ... : SIGINT\n");

	pause();

	printf("after 2nd signal handler\n");

	return 0;
}

