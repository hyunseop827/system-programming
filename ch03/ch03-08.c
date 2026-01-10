/*
 * link
 *
 * make hard link.
 * hard link: make file name to access certain file, using same i-node with original.
 * link count increases.
 * returns 0 if it's successed, else return -1.
 *
 * #include <unistd.h>
 *
 * int link(const char *oldpath, const char *newpath);
 *
 * oldpath: original path of file
 * newpath: new path of link
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	struct stat statbuf;

	stat("linux.txt", &statbuf);
	printf("Before link count= %d\n", (int)statbuf .st_nlink);

	link("linux.txt","linux.ln");

	stat("linux.txt", &statbuf);
	printf("After link count= %d\n", (int)statbuf .st_nlink);
}

