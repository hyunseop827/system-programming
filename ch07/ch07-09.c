/*
 * waitpid
 *
 * waitpid wait certian process with PID.
 * watipid also waits process and store exit status, and return options condition.
 *
 * `pid_t pid` argument.
 *
 * lower than -1: request exit status among the chidren processes in group,  which has ultimate number of PID.
 * exact -1: request exit status from random child processes.
 * exact 0: request exit status from random process in group where the process which calls the function.
 * more than 0: request eixt status from `PID` process.
 *
 *
 * option argument.
 *
 * WCONTINUED: return exit status from running child process.
 * WNOHANG: even can't return exit status from pid process, it doesn't block the PID process and able to do other tasks.
 * WNOWAIT: make process which just returned exit status as `wait`
 * WUNTRACED: return exit status from child process which stops running. since the child proccess stops, it doesn't return exit status.
 *
 * #include <sys/types.h>
 * #include <sys/wait.h>
 *
 * pid_t waitpid(pid_t pid, int *wstatus, int options);
 *
 * pid: pid which waits to end.
 * status: address for exit status.
 * option: options for waitpid().
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int status;
	pid_t pid;

	if ((pid = fork()) < 0) { /* fork failed */
		perror("fork");
		exit(1);
	}

	if (pid == 0) { /* child process */
		printf(" ---> child process\n");
		sleep(3);
		exit(1);
	}

	printf(" ---> parent process\n");

	// WNOHANG = no blocking...
	while ( waitpid(pid, &status, WNOHANG) == 0){
		printf("parent still wait...\n");
		sleep(1);
	}

	printf("child exit status: %d\n", status >> 8);

	return 0;
}

