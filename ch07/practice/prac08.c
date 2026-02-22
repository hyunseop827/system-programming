/*
 * using `fork()` in child process, print directory path and in parent print directory list
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;

	switch (pid = fork()){
		case -1:
			perror("fork()");
			exit(1);
			break;
		case 0:
			system("pwd");
			exit(0);
			break;
		default:
			system("ls -l");
			exit(0);
			break;
	}

	printf("end of fork\n");

	return 0;
}

