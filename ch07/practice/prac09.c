/*
 * using `vfork()` in child process, which prints the login user name. 
 * in parent process, print current time
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	pid_t pid;

	switch (pid = vfork()){
		case -1:
			perror("vfork()");
			exit(1);
			break;
			
		case 0: //child process
			if(execlp("whoami", "whoami", "", (char *) NULL) == -1){
				perror("execlp");
				exit(1);
			}
			break;

		default:
			struct tm *tm;
			time_t timep;

			time(&timep);

			tm = gmtime(&timep);

			printf("%d-%d-%d, %d:%d:%d\n", (tm->tm_year) + 1900, tm->tm_mon, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
			break;
	}
	
	printf("end of vfork()\n");

	return 0;
}
