/*
 * waitid
 *
 * waitid is provided as POSIX standard.
 * waitid also can wait certain process. unlike `waitpid`, waitid can defind in specific ways.
 *
 * `idtype`: assign process to wait
 * 	- P_PID: wait child process which ahs same PID as id.
 * 	- P_GID: wait child process which has same GID as id.
 * 	- P_ALL: wait all children processes, id doesn't take part in here.
 * `id`: assign certain number to distinguish process, such as PID or GID.
 * `infop`: if waitid successfully returns value, it returns `siginfo_t` struct.
 * 	- `siginfo_t` struct
 * 		- si_pid: child process's pid.
 * 		- si_uid: child process's uid.
 * 		- si_signo: signal, it's always `SiGCHLD`.
 * 		- si_status: exit status from child process.
 * 		- si_code: code for reason of exit status.
 * 			- CLD_EXITED: child process calls `_exit()` and exit.
 * 			- CLD_KILLED: child process exits after signal.
 * 			- CLD_DUMPED: core dump after signal.
 * 			- CLD_STOPPED: child process is stopped by signal.
 * 			- CLD_CONTINUE: child process still runs after SIGCONT signal.
 * `options`: waitid's return options could be linked with `or`
 * 	- WEXITED: wait until child process finishs.
 * 	- WSTOPPED: wait child process which stops by signal.
 * 	- WCONTINUED: wait chid process which runs by signal.
 * 	- WNOHANG: same as waitpid().
 * 	- WNOWAIT: make process which just returns exit status wait.
 *
 * wait id returns 0 when it's successful, else it returns -1.
 *
 * #include <sys/types.h>
 * #include <sys/wait.h>
 *
 * int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
 * 
 * idtype: define the type of child process who waits to end.
 * id: id
 * infop: pointer of siginfo_t
 * options: return condition.
 *
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int status;
	pid_t pid;
	siginfo_t infop;

	if ((pid= fork()) < 0){
		perror("fork");
		exit(1);
	}

	if(pid == 0){
		printf("--> child process\n");
		sleep(2);
		exit(2);
	}

	printf("--> parent process\n");
	
	while (waitid(P_PID, pid, &infop, WEXITED) != 0){
		printf("parent still wait... \n");
	}

	printf("child pid: %d\n",infop.si_pid);
	printf("child gid: %d\n",infop.si_uid);
	printf("child code: %d\n",infop.si_code);
	printf("child status: %d\n",infop.si_status);

	return 0;
}

