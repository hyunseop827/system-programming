/*
 * send SIGUSR1 to itself. and print it out.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main() {
	printf("before\n");
	kill(getpid(), SIGUSR1);

	printf("after\n");
	return 0;
}

