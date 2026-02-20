/*
 * execv()
 *
 * run file from `pathname` and provides arguments in argv.
 * argv is pointer array, end of array should be NULL
 *
 * #include <unistd.h>
 *
 * int execv(const char *pathname, char *const argv[]);
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *argv[3];

	printf("before exec funtion\n");

	argv[0] = "ls";
	argv[1] = "-a";
	argv[2] = NULL;

	if (execv("/usr/bin/ls", argv) == -1){
		perror("execv");
		exit(1);
	}

	printf("after exec funtion\n");

	return 0;
}

