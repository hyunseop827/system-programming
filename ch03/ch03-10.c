/*
 * lstat
 *
 * search infos of symbolic link.
 * stat, shows original file's info.
 *
 * #include <sys/types.h>
 * #include <sys/stat.h>
 * #include <unistd.h>
 *
 * int lstat(const char *pathname, struct stat *statbuf);
 *
 * pathname: symbolic link's path
 * statbuf: struct to store infos.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	struct stat statbuf;

	printf("1. stat: linux.txt ----\n");
	stat("linux.txt", &statbuf);
	printf("linux.txt: link count =%d\n", (int)statbuf .st_nlink);
	printf("linux.txt: I-node= %d\n", (int)statbuf .st_ino);

	printf("2. stat: linux.txt ----\n");
	stat("linux.txt", &statbuf);
	printf("linux.txt: link count =%d\n", (int)statbuf .st_nlink);
	printf("linux.txt: I-node= %d\n", (int)statbuf .st_ino);

	printf("3. stat: linux.txt ----\n");
	lstat("linux.txt", &statbuf);
	printf("linux.txt: link count =%d\n", (int)statbuf .st_nlink);
	printf("linux.txt: I-node= %d\n", (int)statbuf .st_ino);
}

