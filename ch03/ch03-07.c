/*
 * chmod
 *
 * to change access permission of file.
 *
 * fchmod can be substitude.
 *
 * #include <sys/stat.h>
 *
 * int chmod(const char *pathname, mode_t mode);
 *
 * pathname: file path
 * mode: perrmission
 *
 * to change mode, use constants to check permission.
 * to adjust permission `OR |` could be used.
 * `NOT ~` `AND &` also can be used.
 *
 * fchmod
 * 
 * #include <sys/stat.h>
 *
 * int fchmod(int fd, mode_t mode);
 *
 * fd: file discripter
 * mode: permission
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
	struct stat statbuf;

	chmod("linux.txt", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);

	stat("linux.txt", &statbuf);
	printf("1. mode: %o\n", (unsigned int)statbuf .st_mode);

	statbuf .st_mode |= S_IWGRP;
	statbuf .st_mode &= ~(S_IROTH);

	chmod("linux.txt", statbuf .st_mode);

	stat("linux.txt", &statbuf);
	printf("2. mode: %o\n", (unsigned int)statbuf .st_mode);
}

