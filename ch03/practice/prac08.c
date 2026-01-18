/*
 * CLA, print file's info.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

	int n = argc;

	if(n>=3 || n == 1){
		printf("only 1 argument is required\n");
		exit(1);
	}

	struct stat statbuf;
	char* file = argv[1];

	int result = stat(file, &statbuf);

	if (result == -1){
		perror("stat");
		exit(1);
	}

	int kind = (unsigned int)statbuf.st_mode & S_IFMT;
	char *type;

	switch(kind){
		case S_IFLNK:
			type = "symbloic link";
			break;
		case S_IFSOCK:
			type = "socket file";
			break;
		case S_IFREG:
			type = "regular file";
			break;
		case S_IFBLK:
			type = "block device special file";
			break;
		case S_IFDIR:
			type = "directory";
			break;
		case S_IFCHR:
			type = "charater special file";
			break;
		case S_IFIFO:
			type = "FIFO file";
			break;
		default:
			perror("st_mode");
			break;
	}


	printf("file name: %s\n", file);
	printf("i node: %d\n",(int)statbuf.st_ino);
	printf("file type: %s\n",type);
	printf("permission: %d\n",(int)statbuf.st_mode);
	printf("UID: %d\n",(int)statbuf.st_uid);

	return 0;
}

