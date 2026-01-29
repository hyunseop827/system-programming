/*
 * using low-level file IO, make directory in `.` and move file
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("2 arguments requireded\n");
		exit(1);
	}

	char* dir = argv[1];
	char* file = argv[2];

	// make dir
	if(mkdir(dir,0755) == -1){
		perror("mkdir");
		exit(1);
	}

	// open original file
	int fd1;
	if ((fd1 = open(file, O_RDONLY)) == -1){
		perror("open");
		exit(1);
	}

	// new path
	char new_path[BUFSIZ];
	snprintf(new_path,sizeof(new_path),"%s/%s",dir,file);

	// move file.
	// file IO
	int fd2;
	if((fd2 = open(new_path, O_CREAT | O_EXCL | O_WRONLY ,0644)) == -1){
		perror("open");
		exit(1);
	}

	int n;
	char buf[BUFSIZ];

	while ((n = read(fd1,buf,10)) > 0){
		if (write(fd2,buf,n) != n) perror("write");
	}

	close(fd1);
	close(fd2);

	// remove original file.
	if(unlink(file) == -1){
		perror("unlink");
		exit(1);
	}

	return 0;
}

	
	

