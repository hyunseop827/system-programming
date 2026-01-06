/*
 * use mkdir make dir1 and dir2
 * use rmdir to delete dir1
 * use rename to dir2
 *
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {

	if(mkdir("dir1",0755) == -1){
		perror("dir1");
		exit(1);
	}
	else{
		printf("successfully make dir1\n");
	}

	if(mkdir("dir2",0755) == -1){
		perror("dir2");
		exit(1);
	}
	else{
		printf("successfully make dir2\n");
	}

	// delete and rename
	printf("----------\n");

	printf("delete dir1 =======\n");
	if(rmdir("dir1") == -1){
		perror("dir1");
		exit(1);
	}
	else{
		printf("succesfuly delete dir1\n");
	}

	printf("rename dir2 =======\n");
	if (rename("dir2","newdir2") == -1){
		perror("rename");
		exit(1);
	}
	else{
		printf("successfully rename dir2\n");
	}
}

