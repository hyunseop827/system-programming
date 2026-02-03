/*
 * getlogin
 *
 * returns user login name who launchs currently process.
 *
 * #include <unistd.h>
 *
 * char *getlogin(void);
 *
 */

/*
 * getuid/geteuid
 *
 * returns currently process's ID.
 * RUID: Real User ID, UID reacts to real user name
 * EUID: Effective User ID, it is used to assgin permission in process. right after login, RUID and EUID are same, after launching setuid program or change to other user's ID, it can be different.
 *
 * #include <unistd.h>
 * #include <sys/types.h>
 *
 * uid_t getuid(void);
 * uid_t geteuid(void);
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	uid_t uid, euid;
	char *name;

	uid = getuid();
	euid = geteuid();
	name = getlogin();

	printf("login name: %s\nUID: %d\nEUID: %d\n",name,(int)uid,(int)euid);

	return 0;
}

