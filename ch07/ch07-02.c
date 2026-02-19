/*
 * fork
 *
 * fork return child's PID to parent, and 0 to child.
 * it returns -1 when it's failed.
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t fork(void);
 *
 */

/*
 * vfork()
 *
 * vfork also makes new process yet, doesn't copy all memory. vfork is old function so not recommended.
 *
 * #include <unistd.h>
 *
 * pid_t vfork(void);
 *
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	pid_t pid;

	switch(pid = fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("child process - My PID: %d, my parent PID: %d\n",
					(int)getpid(), (int)getppid());
			break;
		default:
			printf("parent process - My PID: %d, my parent PID: %d, My child's PID: %d\n", (int)getpid(), (int)getppid(), (int)pid);
			break;
	}

	printf("end of fork()\n");

	return 0;
}

