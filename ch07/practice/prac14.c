/*
 * using `execvp()` and launch vi and open `/etc/hosts`
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	
	printf("before execvp()\n");

	char *argv[] = {"vi", "/etc/hosts", NULL};

	if (execvp("vi", argv) == -1){
		perror("execvp");
		exit(1);
	}

	printf("after execvp()\n");

	return 0;
}

