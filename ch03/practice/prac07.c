/* 
 * write a program
 * with CLA, returns arugment file's type.
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
		printf("only 1 argument is needed\n");
		exit(1);
	}

	// file checks
	char *file= argv[1];
	struct stat statbuf;

	int result = stat(file, &statbuf);

	if (result == -1){
		perror("stat");
		exit(1);
	}

	int kind = (unsigned int)statbuf.st_mode & S_IFMT;

	switch(kind){
		case S_IFLNK:
			printf("%s: symbolic link\n",file);
			break;
		case S_IFSOCK:
			printf("%s: socket file\n",file);
			break;
		case S_IFREG:
			printf("%s: regular file\n",file);
			break;
		case S_IFBLK:
			printf("%s: block device special file\n",file);
			break;
		case S_IFDIR:
			printf("%s: directory\n",file);
			break;
		case S_IFCHR:
			printf("%s: charater special file\n",file);
			break;
		case S_IFIFO:
			printf("%s: FIFO file\n",file);
			break;
		default:
			perror("st_mode");
			break;
	}

	return 0;
}

