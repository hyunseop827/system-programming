/*
 * fstat
 * 
 * #include <sys/type.h>
 * #include <sys/stat.h>
 * #include <unistd.h>
 *
 * int fstat(int fd, struct stat *statbuf);
 *
 * fd: file discripter for file has opening.
 * statbuf: add of struct to store infos.
 *
 * get file discripter, and search path then store at statbuf.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int fd;
	struct stat statbuf;

	fd = open("linux.txt", O_RDONLY);
	if (fd == -1){
		perror("open: linux.txt");
		exit(1);
	}

	fstat(fd, &statbuf);

	printf("I-node= %d\n", (int)statbuf .st_ino);
	printf("UID= %d\n", (int)statbuf .st_uid);
	close(fd);
}

