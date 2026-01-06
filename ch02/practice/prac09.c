/*
 * in ch02-06.c there is no code for print error.
 * especially getcwd.
 * improve code with error printing.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *cwd;

	cwd = getcwd(NULL, BUFSIZ);
	if (cwd == NULL){
		perror("cwd");
		exit(1);
	}
	printf("1. Current Directory: %s\n",cwd);

	if (chdir("bit") == -1){
		perror("bit");
		exit(1);
	}

	

	cwd = getcwd(NULL,BUFSIZ);
	if (cwd == NULL){
		perror("cwd");
		exit(1);
	}
	printf("2. Current Directory: %s\n",cwd);

	free(cwd);
}

