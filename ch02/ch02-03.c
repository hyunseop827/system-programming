/*
 * getcwd
 *
 * returns absolute path.
 *
 * #include <unistd.h>
 *
 * char *getcwd(char *buf, size_t size);
 *
 * buf: address to store path.
 * size: size of buffer.
 *
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

	// BUFSIZ is written in stdio.h, as 8192
	char *cwd;
	char wd1[BUFSIZ];
	char wd2[10];

	// [1] allocate enough memory in buf, and give size.
	getcwd(wd1, BUFSIZ);
	printf("wd1 = %s\n",wd1);

	// [2] assign NULL in buf, and give size of memory need to be allocated.
	// needs to call `free`
	cwd = getcwd(NULL, BUFSIZ);
	printf("cwd1= %s\n",cwd);
	free(cwd);

	// [3] assign NULL in buf, and give 0 in size.
	// needs to call `free`
	cwd = getcwd(NULL,0);
	printf("cwd2 = %s\n",cwd);
	free(cwd);

	// [4] give wrong bufsize.
	if (getcwd(wd2, 10) == NULL) {
		perror("getcwd");
		exit(1);
	}
}

