/*
 * getting PID from CLA, and print it's PGRPID, session ID.
 * if it's 0, print current's one
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	
	if (argc != 2){
		printf("just one argument needed\n");
		exit(1);
	}

	for (int i = 0; argv[1][i] != '\0'; i++) {
 	   if (!isdigit((unsigned char)argv[1][i])) {
        	printf("only number can be acceptable\n");
        	exit(1);
   	 }
	}

	int pid = atoi(argv[1]);

	if(pid!=0){
		pid_t pgid = getpgid(pid);
		pid_t session_id = getsid(pid);
		
		printf("pgid: %d\nseesion_id: %d\n",pgid,session_id);
		return 0;
	}
	else{
		pid_t ppid = getppid();
		pid_t pgid = getpgrp();
		pid_t session_id = getsid(0);

		printf("ppid: %d\npgid: %d\nsession_id: %d\n",ppid,pgid, session_id);
		return 0;
	}
}

