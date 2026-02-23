/*
 * re-write prac15 with waitid().
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

	int status;
	pid_t pid;
	siginfo_t infop;

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
			break;

		default:
			// parent
			printf("parent process\n");

			while(1){
				memset(&infop, 0, sizeof(infop));

				int r = waitid(P_PID, pid, &infop, WEXITED | WNOHANG);

				if(r == -1){
					perror("waitid");
					exit(1);
				}

				// when it's fully done, so infop has child process's info.
				if (infop.si_pid != 0) break;

				printf("parent still waiting... \n");
				sleep(1);
			}

			break;
	}

	printf("end of fork()\n");

	printf("child PID: %d\n", infop.si_pid);
	printf("child UID: %d\n", infop.si_uid);
	printf("child code: %d\n", infop.si_code);
	printf("child status: %d\n", infop.si_status);
	
	return 0;
}

