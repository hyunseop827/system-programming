/*
 * using `waitpid()` and modify prac13.c, make process wait the child process.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	
	int status;
	pid_t pid;

	switch (pid = fork()) {

		case -1:
			perror("fork()");
			exit(1);
			break;

		case 0:
			// child
			printf("child process\n");
			sleep(3);

			if (execl("/usr/bin/who", "who", (char *)NULL) == -1){
				perror("execl");
				exit(1);
			}
			sleep(3);
			break;

		default:
			// parent
			printf("parent process\n");

			break;
	}

	printf("end of fork()\n");

	while(waitpid(pid, &status, WNOHANG) == 0){
		printf("parent still waiting...\n");
		sleep(1);
	}

	printf("child process exit status: %d\n", status >> 8);


	return 0;
}

