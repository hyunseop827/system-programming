/*
 * `sys/stat.h` has constants to check access right.
 * just shit constants and do AND calc gives you result.
 *
 * or in POSIX, there are each constants for CRUD permission for user/group/other.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
	struct stat statbuf;

	stat("linux.txt", &statbuf);
	printf("mode= %o\n", (unsigned int)statbuf .st_mode);

	if ((statbuf .st_mode & S_IREAD) != 0)
		printf("linux.txt: User has a read permission\n");

	if ((statbuf .st_mode &(S_IREAD >> 3)) != 0)
		printf("linux.txt: Group has a read permission\n");

	if ((statbuf .st_mode & S_IROTH) != 0)
		printf("linux.txt: Other have a read permission\n");
}

