/* 
 * write a program
 * with CLA, returns arugment file's size.
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

	if(result == -1){
		printf("error occurs\n");
		perror("stat");
		exit(1);
	}

	int size = (int)statbuf.st_size;

	printf("%s size= %d\n",file,size);

	return 0;
}

