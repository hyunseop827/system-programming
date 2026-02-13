/*
 * getpid
 *
 * return pid of process who calls this function.
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t getpid(void);
 *
 */

/*
 * getppid
 *
 * return parent - pid of process who calls this function.
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t getppid(void);
 *
 */

#include <unistd.h>
#include <stdio.h>

int main() {
	printf("PID: %d\n", (int)getpid());
	printf("PPID: %d\n", (int)getppid());

	return 0;
}

