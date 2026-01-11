/*
 * realpath
 *
 * to check real path of symbolic link's original file.
 *
 * #include <limits.h>
 * #include <stdlib.h>
 *
 * char *realpath(const char *path, char *resolved_path);
 *
 * path: symbolic link's path
 * resolved_path: address of buffer to store path
 *
 * returns address when it's successed, else `NULL`.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	char buf[BUFSIZ];

	realpath("linux.sym",buf);
	printf("linux.sym: REALPATH= %s\n",buf);
}

