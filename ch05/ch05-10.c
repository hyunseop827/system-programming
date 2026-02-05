/*
 * getgid, getegid
 *
 * >> getgid reads real group ID
 * >> getegid return effective group ID
 *
 * #include <unistd.h>
 * #include <sys/types.h>
 *
 * gid_t getgid(void);
 * gid_t getegi(void);
 *
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	gid_t gid, egid;

	gid = getgid();
	egid = getegid();

	printf("GID=%d, EGID= %d\n", (int)gid, (int)egid);

	return 0;
}


