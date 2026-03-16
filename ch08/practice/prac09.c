/*
 * assign signal and set SIGQUIT, SIGILL, SIGTRAP
 * code program to check if SIGILL is assigned.
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	sigset_t st;

	sigemptyset(&st);

	sigaddset(&st, SIGQUIT);
	sigaddset(&st, SIGILL);
	sigaddset(&st, SIGTRAP);

	if(sigismember(&st, SIGILL))
		printf("SIGILL has been set.\n");

	return 0;
}


