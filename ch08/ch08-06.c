/*
 * sigaction struct
 *
 * struct sigaction {
 * 	void (*sa_handler)(int);
 * 	void (*sa_sigaction)(int, siginfo_t *, void *);
 * 	sigset_t sa_mask;
 * 	int sa_flags;
 * 	void (*sa_restorer)(void);
 * };
 *
 * - sa_handler and sa_sigaction
 *   	sa_handler and sa_sigaction assign action to handler signals.
 *   	in some system sa_handler and sa_sigaction are defined as union
 *
 * struct sigaction {
 * 	int sa_flags;
 * 	union {
 * 		void (*sa_handler)();
 * 		void (*sa_sigaction)(int, siginfo_t *, void *);
 * 	} _funcptr;
 * 	sigset_t sa_mask;
 * };
 *
 * - sa_mask
 *   	it assign signal set to be blocked.
 *
 * - sa_flags
 *   	assign flag to deliever the signal.
 */

/*
 * sigaction()
 *
 * #include <signal.h>
 *
 * int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
 *
 * signum: signal to process.
 * act: address of struct
 * oldact: address of old struct signals.
 *
 * signum could be anything except SIGKILL and SIGSTOP.
 * act and old act are struct of signals.
 * it returns 0 when it's successful, else returns -1.
 */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo) {
	psignal(signo, "recieved signal:");
	sleep(5);
	printf("in signal handler, after sleep\n");
}

int main() {
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);

	act.sa_flags = 0;
	act.sa_handler = sig_handler;

	if(sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0){
		perror("sigaction");
		exit(1);
	}

	fprintf(stderr, "input SIGINT: ");
	pause();
	fprintf(stderr, "after signal handler\n");

	return 0;
}

