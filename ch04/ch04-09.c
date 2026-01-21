/*
 * fcntl
 *
 * to adjust flag of file discriptor
 *
 * `fcmt()`'s `cmd`s are written in `fcntl.h`.
 *
 * `F_GETFL` read value of status flag.
 * `F_SETFL` set value of status flag. (flags usually used in OPEN())
 *
 * #include <unistd.h>
 * #include <fcntl.h>
 *
 * int fcntl(int fd, int cmd, ... // arg //);
 *
 * fd: file discriptor.
 * cmd: command.
 * arg: arguments for cmd.
 *
 */

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int fd, flags;

	fd = open("linux.txt", O_RDWR);
	if (fd == -1){
		perror("open");
		exit(1);
	}

	if ((flags = fcntl(fd, F_GETFL)) == -1){
		perror("fcntl");
		exit(1);
	}

	flags |= O_APPEND;

	if (fcntl(fd, F_SETFL, flags) == -1){
		perror("fcntl");
		exit(1);
	}

	if (write(fd, "linux system\n", 13) != 13) perror("write");

	close(fd);

	return 0;
}

