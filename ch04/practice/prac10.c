/*
 * using `lseek()` to print data from file like eg.
 *
 * data: abcdefghi
 * output: acegi
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	if (argc != 2){
		printf("1 argument required\n");
		exit(1);
	}

	char *file = argv[1];
	int fd;

	if((fd=open(file,O_RDONLY)) == -1){
		perror("open");
		exit(1);
	}

	int n;
	char buf[BUFSIZ];
	while((n = read(fd,buf,1)) > 0){
		write(1,buf,1);
		lseek(fd,1,SEEK_CUR);
	}

	return 0;
}

