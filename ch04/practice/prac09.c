/*
 * read file and print it out everything in 3bytes.
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("only 1 argument required\n");
		exit(1);
	}

	char *file = argv[1];
	int rfd;

	// open file
	if((rfd = (open(file,O_RDONLY))) == -1){
		perror("open");
		exit(1);
	}

	int bufsize = 3;
	char buf[4];
	char space = ' ';
	ssize_t n;

	while((n = read(rfd,buf,bufsize)) > 0){
		write(1,buf,n);
		write(1,&space,1);
	}
	
	return 0;
}

