/*
 * getpgrp, getpgid
 *
 * `getpgrp()` returns PGID of process calling this function.
 * `getpgid()` returns PGID of arguments. if argument is 0, it works as getpgrp.
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t getpgrp(void);
 * pid_t getpgid(pid_t pid);
 *
 * pid: ID of proccess.
 *
 */

/*
 * setpgid
 *
 * change pgid, set pid's pgid as pgid in argument.
 * if pid is 0, then it calles current proccess pid.
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * int setpgid(pid_t pid, pid_t pgid);
 *
 * pid: process ID in a group.
 * pgid: new PGID.
 *
 */

#include <unistd.h>
#include <stdio.h>

int main() {

	printf("PID: %d\n", (int)getpid());
	printf("PGRP: %d\n", (int)getpgrp());
	printf("PGID: %d\n", (int)getpgid(0));
	printf("PGID(18020): %d\n", (int)getpgid(18020));

	return 0;
}


