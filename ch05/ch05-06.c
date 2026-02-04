/*
 * getpwname
 *
 * return struct passwd address when it's successful, else return NULL
 * it gives name's info from `/etc/passwd`
 *
 * #include <sys/types.h>
 * #include <pwd.h>
 *
 * struct passwd *getpwname(const char *name);
 * 
 * name: login name
 *
 */

#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>

int main() {
	struct passwd *pw;

	pw = getpwnam("user1");

	printf("UID: %d\n",(int)pw->pw_uid);
	printf("home directory: %s\n", pw->pw_dir);

	return 0;
}

