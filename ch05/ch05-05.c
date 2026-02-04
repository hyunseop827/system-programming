/*
 * passwd struct
 *
 * struct passwd {
 * 	char *pw_name; // login name
 * 	char *pw_passwd; // passwd, but most of recent Linux system store password in `/etc/shadow`.
 * 	uid_t pw_uid; // UID
 * 	gid_t pw_gid; // GID
 * 	char *pw_gecos; // etc
 * 	char *pw_dir; // home directory
 * 	char *pw_shell; // login shell
 * }
 */

/*
 * getpwuid
 *
 * returns passwd struct address if it's success, else return NULL
 *
 * #include <sys/types.h>
 * #include <pwd.h>
 *
 * struct passwd *getpwuid(uid_t uid);
 *
 * uid: uid to search
 *
 */

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>

int main() {
	struct passwd *pw;

	pw = getpwuid(getuid());
	printf("UID: %d\n", (int)pw->pw_uid);
	printf("login name: %s\n", pw->pw_name);

	return 0;
}

