/*
 * fchdir
 *
 * move to directory.
 *
 * #include <unistd.h>
 *
 * int fchdir(int fd);
 *
 * fchdir requires file descripter as argument.
 * returns 0 if it successes, else returns -1.
 *
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	char *cwd;
	int fd;

	cwd = getcwd(NULL,BUFSIZ);
	printf("1. Current Directory: %s\n", cwd);

	// `O_RDONLY' is written in fcntl.h
	fd = open("bit", O_RDONLY);
	fchdir(fd);

	cwd = getcwd(NULL, BUFSIZ);
	printf("2. Current Directory: %s\n", cwd);

	close(fd);
	free(cwd);
}

