/*
 * unlink
 *
 * delete link
 *
 * #include <unistd.h>
 *
 * int unlink(const char *pathname);
 *
 * path: path to delete link
 *
 */

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	struct stat statbuf;

	stat("linux.ln", &statbuf);
	printf("1.linux.ln: link count= %d\n", (int)statbuf .st_nlink);

	unlink("linux.ln");

	stat("linux.txt",&statbuf);
	printf("2.linux.txt: link count= %d\n", (int)statbuf .st_nlink);

	unlink("linux.sym");
}

