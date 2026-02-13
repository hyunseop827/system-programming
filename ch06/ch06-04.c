/*
 * getsid
 *
 * search session id of process.
 * if pid is 0, it returns current process's seesion id.
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t getsid(pid_t pid);
 */

/*
 * setsid
 *
 * create session
 * the process calling isn't proccess group then it makes new session and assign current process and session and proccess's group reader.
 * so the current process will be only one in session and group.
 * returns -1 when it's failed.
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t setsid(void);
 *
 */

#include <unistd.h>
#include <stdio.h>

int main() {
	printf("PID: %d\n", (int)getpid());
	printf("PGID: %d\n", (int)getpgrp());
	printf("SID: %d\n", (int)getsid(0));

	return 0;
}

