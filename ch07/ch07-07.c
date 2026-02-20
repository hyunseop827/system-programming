/*
 * exec exchange the whole process so usually to make child process,
 * fork and exec work together.
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid;

	switch(pid = fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("---> child process\n");
			if(execlp("ls","ls","-a", (char*) NULL) == -1){
				perror("execlp");
				exit(1);
			}
			exit(0);
			break;
		default:
			printf("---> parent process my PID: %d\n", (int)getpid());
			break;
	}

	return 0;
}

