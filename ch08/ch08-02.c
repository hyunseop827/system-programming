/*
 * signal
 *
 * #include <signal.h>
 *
 * typedef void (*sighandler_t)(int);
 * sighandler_t signal(int signum, sighandler_t handler);
 *
 * signum: signal to process in signal handler.
 * handler: name of signal handler function.
 *
 * signal function is most basic function to process signal, also can assign function when it gets signal.
 * in `signum` can be placed with anything except SIGKILL and SIGSTOP.
 * handler can be placed with ways to process signal.
 *
 * handler could be one among these.
 * signal handler address.
 * SIG_IGN: ignore signal.
 * SIG_DFL: assign basic protocol to process signal.
 *
 * handler function returns void, because the returning result can't be in process.
 * signal function returns signal address when it's success, else return SIG_ERR.
 * if handler is address of function and signum is not either SIGKILL or SIGSTOP.
 * signal function work differently in system.
 *
 * - SYSTEM V: after process signal, it assign to basic protocol (SIG_DFL). to continue processing signal, needs to call signal() function and assign it again.
 * - BSD: it doesn't assign to SIG_DFL, so signal handler keeps working.
 * - LINUX: signal(2) works as SYSTEM V, yet gcc (glibc2)'s signal(3) works as BSD.
 */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo) {
	printf("signal handler signum: %d\n", signo);
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

