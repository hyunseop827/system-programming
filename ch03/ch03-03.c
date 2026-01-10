/*
 * in `sys/stat.h`, there are constants related to file types.
 * st_mode & `AND` S_IFMT (017000) results file's type constant.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
	struct stat statbuf;
	int kind;

	stat("linux.txt", &statbuf);

	printf("mode= %o\n", (unsigned int)statbuf .st_mode);
	kind = statbuf .st_mode & S_IFMT;
	printf("kind= %o\n", kind);

	switch (kind) {
		case S_IFLNK:
			printf("linux.txt: Symbolic Link\n");
			break;
		case S_IFDIR:
			printf("linux.txt: Directory\n");
			break;
		case S_IFREG:
			printf("linux.txt: Regular File\n");
			break;
	}
}

