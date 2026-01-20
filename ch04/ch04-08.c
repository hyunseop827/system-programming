/*
 * dup2
 *
 * `dup()` allocates new file discripter automatically.
 * However `dup2()` allows you to allocate new file discripter.
 *
 * #include <unistd.h>
 *
 * int dup2(int oldfd, int newfd);
 *
 * oldfd: file discripter to copy.
 * newfd: file discripter to be copied.
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int fd;
	
	fd = open("tmp.bbb", O_CREAT | O_WRONLY | O_TRUNC,0644);

	if(fd == -1){
		perror("create tmp.bbb"); 
		exit(1);
	}

	dup2(fd,1);
	printf("DUP2: standard output redirection\n");

	close(fd);
}

