/*
 * chdir
 *
 * move to certain directory.
 *
 * #include <unistd.h>
 *
 * int chdir(const char *path);
 *
 * absolute and relative path, both could be used.
 * returns 0 if it successes, else returns -1.
 * 
 * it only changes directory in program, not in shell.
 * so even if the program successed, pwd would be same as before.
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *cwd;

	cwd = getcwd(NULL, BUFSIZ);
	printf("1. Current Directory: %s\n",cwd);

	chdir("bit");

	cwd = getcwd(NULL,BUFSIZ);
	printf("2. Current Directory: %s\n",cwd);

	free(cwd);
}

