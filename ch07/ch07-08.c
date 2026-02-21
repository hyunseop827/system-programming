/*
 * wait
 *
 * wait make parent process wait till child process ends.
 * end status will be in `wstatus`
 * if parent process ends before child process ends, wait immediately returns.
 * wait returns child's PID, if it's -1 it means there is no child.
 *
 * #include <sys/types.h>
 * #include <sys/wait.h>
 *
 * pid_t wait(int *wstatus);
 *
 * wstatus: address to store end status.
 *
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int status;
	pid_t pid;

	switch (pid = fork()) {
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("---> child process\n");
			exit(2);
			break;
		default:
			while(wait(&status) != pid)
				continue;
			printf("---> parent process\n");
			printf("status: %d, %x\n",status, status);
			printf("child process exit status:%d\n", status >> 8);
			break;
	}

	return 0;
}

