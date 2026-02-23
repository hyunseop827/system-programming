/*
 * modify code of prac10.c, to print PPID of children
 *
 */

#define MAX_LEN 3

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	for(int i = 0 ; i < MAX_LEN; i++){
		pid_t pid = fork();

		switch(pid){
			case -1:
				perror("fork()");
				exit(1);
				break;
			case 0:
				printf("%d: child\n",i);
				printf("PID: %d, PPID: %d\n", (int)getpid(), (int)getppid());
				break;
			default:
				printf("%d: parent\n",i);
				printf("PID: %d, PPID: %d\n", (int)getpid(), (int)getppid());
				break;
		}
	}

	printf("end of fork()\n");
	return 0;
}

