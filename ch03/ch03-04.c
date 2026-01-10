/*
 * besides constant in `sys/stat.h` there are macros.
 * macros do AND calculation with mode & 0xF000.
 * results are compared to certain value to check the type of file.
 *
 * checking value is same as constants.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
	struct stat statbuf;
	int kind;

	stat("linux.txt", &statbuf);

	printf("Mode= %o\n", (unsigned int)statbuf .st_mode);

	if(S_ISLNK(statbuf .st_mode))
		printf("linux.txt: Symbolic Link\n");
	if(S_ISDIR(statbuf .st_mode))
		printf("linux.txt: Directory\n");
	if(S_ISREG(statbuf .st_mode))
		printf("linux.txt: Regualr file\n");
}

