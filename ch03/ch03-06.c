/*
 * access
 *
 * function to check if file has mode permission.
 * yet only can check if ID (RUID)'s permission.
 * returns 0 if it has, else return -1.
 *
 * mode can be: R_OK, W_OK, X_OK, F_OK
 *
 * #include <unistd.h>
 *
 * int access(const char *pathname, int mode);
 *
 * pathname: path.
 * mode: perrmission mode
 *
 */

#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;

int main() {
	int perm;

	if(access("linux.bak", F_OK) == -1 && errno == ENOENT)
		printf("linux.bak: File doesn't exsit\n");

	perm = access("linux.txt", R_OK);

	if (perm == 0)
		printf("linux.txt: Read permission is permitted.\n");

	else if (perm == -1 && errno == EACCES)
		printf("linux.txt: Read permission is not permitted.\n");
}

