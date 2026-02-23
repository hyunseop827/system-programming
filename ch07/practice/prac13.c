/*
 * write code, using `fork()` make child process and `execl()` to execute who.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid;

	switch (pid = fork()) {

		case -1:
			perror("fork()");
			exit(1);
			break;

		case 0:
			// child
			printf("child process\n");

			if (execl("/usr/bin/who", "who", (char *)NULL) == -1){
				perror("execl");
				exit(1);
			}
			break;

		default:
			// parent
			printf("parent process\n");

			break;
	}

	printf("end of fork()\n");

	return 0;
}

