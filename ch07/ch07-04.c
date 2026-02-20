/*
 * execlp()
 *
 * run `file` program and argument is `arug0 ~ argn`
 * arguments are pointer, arguments at the end should be NULL
 *
 * #include <unistd.h>
 *
 * int execlp(const char *file, const char *arg, .../ (char* NULL)/);
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("---> before exec function\n");

	if (execlp("ls","ls","-a", (char*)NULL) == -1){
		perror("execlp");
		exit(1);
	}

	printf("---> after exec funtion\n");
	
	return 0;
}

