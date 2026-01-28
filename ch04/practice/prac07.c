/*
 * using low-level file IO, write code that initiates copying.
 */

#define BUFF 10

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("2 arguments requireds\n");
		exit(1);
	}

	char* from = argv[1];
	char* to = argv[2];


	printf("copying form %s to %s\n",from, to);

	// open from.
	int fd1;
	if((fd1 = open(from, O_RDONLY)) == -1){
		perror("open from");
		exit(1);
	}

	// create to
	int fd2;
	if((fd2 = open(to, O_CREAT | O_EXCL | O_WRONLY | O_TRUNC, 0644)) == -1){
			perror("open to");
			exit(1);
	}

	// copying.
	int n;
	char buffer[BUFF];
	while((n = read(fd1, buffer, BUFF)) > 0){
		write(fd2, buffer, n);
	}

	// close.
	close(fd1);
	close(fd2);

	return 0;
}

