#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *argv[3];
	char *envp[2];

	printf("before exec funtion\n");

	argv[0] = "arg.out";
	argv[1] = "100";
	argv[2] = NULL;

	envp[0] = "MTENV=system";
	envp[1] = NULL;

	if (execve("./arg.out",argv,envp) == -1){
		perror("execve");
		exit(1);
	}

	printf("after exec function\n");

	return 0;
}
