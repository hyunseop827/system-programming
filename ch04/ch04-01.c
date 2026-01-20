/*
 * open
 * 
 * usually, 0 is standard input, 1 is standard output.
 * 2 is for standard error output.
 * so, most of time, number 3 is given to file discriptor. 
 * return file discripter when it's successed, else return -1.
 *
 * #include <sys/types.h>
 * #include <sys/stat.h>
 * #include <fcntl.h>
 *
 * int open(const char *pathname, int flags);
 * int open(const char *pathname, int flags, mode_t mode);
 *
 * pathname: file path.
 * flag: flag for status
 * mode: permission
 *
 */

/*
 * creat
 *
 * make file.
 *
 * #include <sys/types.h>
 * #include <sys/stat.h>
 * #include <fcntl.h>
 *
 * int creat(const char *pathname, mode_t mode);
 *
 * pathname: path.
 * mode: permission
 *
 */

/*
 * close
 *
 * close file.
 * return 0 (no error), else -1 (failed).
 *
 * #include <unistd.h>
 *
 * int close(int fd);
 *
 * fd: file discriptor
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
	mode_t mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	fd = open("test.txt", O_CREAT, mode);

	if (fd == -1){
		perror("creat");
		exit(1);
	}

	close(fd);
}

