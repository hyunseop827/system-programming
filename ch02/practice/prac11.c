/*
 * get directory name as CLA
 * and make directory as value of CLA
 * and move to that one.
 *
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	char *dir_name = argv[1];
	printf("name of directory: %s\n", dir_name);

	// make directory
	if (mkdir(dir_name, 0755) == -1){
		perror(dir_name);
		exit(1);
	}

	else{
		printf("directory made: %s\n",dir_name);
	}

	//move to directory
	printf("move to directory\n");

	if(chdir(dir_name) == -1){
		perror(dir_name);
		exit(1);
	}
	
	else{
		printf("moved to %s\n",dir_name);
	}

	//print current path
	
	char *path = get_current_dir_name();
	if (path == NULL){
		perror("get_current_dir_name");
		exit(1);
	}
	else{
		printf("currently you are here: %s\n",path);
	}

	return 0;
}

