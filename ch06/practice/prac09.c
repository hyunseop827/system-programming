/*
 * `ps -ef | grep ssh | more | sleep 200&`, in this pipe line, check the what's the group's PGID.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int pid_original = 0;
	printf("what was the job number?: \n");
	scanf("%d",&pid_original);


	pid_t group_id;

	group_id = getpgid(pid_original);

	printf("Current group id: %d\n", (int)group_id);
}


