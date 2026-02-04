/*
 * getpwent, setpwent, endpwent, fgetpwent
 *
 * #include <sys/types.h>
 * #include <pwd.h>
 *
 * struct passwd *getpwent(void);
 * void setpwent(void);
 * void endpwent(void);
 * struct passwd *fgetwent(FILE *stream);
 *
 * >> `getpwuid()` and `getpwnam()` read infos about argument.
 * >> `getpwent()` read datas from `/etc/passwd` in order, when it's EOF, it returns NULL
 * >> `setpwent()` change offset of `/etc/passwd` to start.
 * >> `endpwent()` close `/etc/passwd`
 * >> 'fgetwent()` get argument as file pointer, so it reads from file where arument points at, not `/etc/passwd`. However the file pointed by pointer should have same structure and format as `/etc/passwd`
 */

#include <pwd.h>
#include <stdio.h>

int main() {
	struct passwd *pw;
	int n;

	for(n = 0; n <3; n++){
		pw = getpwent();
		printf("UID: %d\nLogin name: %s\n",(int)pw->pw_uid, pw->pw_name);
	}
	return 0;
}


