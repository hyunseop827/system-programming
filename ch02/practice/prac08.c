/*
 * make programer that remembers where you were 
 * then move to other directory and comes back.
 *
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	char *path1;
	char *path2;

	// get current path
	path1 = get_current_dir_name();

	if(path1 != NULL){
		printf("Currently you are here: %s\n",path1);
	}

	// move to home
	printf("move to home ~\n");
	if(chdir("/home/hyunseop") == -1){
		perror("~");
		exit(1);
	}
	else{
		path2 = get_current_dir_name();
		printf("Currently you just moved to here: %s\n",path2);
	}

	//come back to where you belong.
	printf("move to where you were\n");
	if(chdir(path1) == -1){
		perror(path1);
		exit(1);
	}
	else{
		path2 = get_current_dir_name();
		printf("Currently you are here: %s\n",path2);
	}
	
}

