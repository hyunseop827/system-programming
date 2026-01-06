/*
 * using CLA, get path and check if it exits
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {

	int n = argc;

	if (n<=2){
		printf("not enough argument.\n");
		exit(1);
	}

	char *target_path = argv[1];

	DIR *dp;
	struct dirent *dent;

	// move to arguments path.
	
	if(chdir(target_path) != 0){
		perror("chdir");
		exit(1);
	}

	// check file.
	char *target_file = argv[2];

	dp = opendir(".");

	if(dp == NULL){
		perror("opendir");
		exit(1);
	}

	while((dent = readdir(dp))){
		char *name_file = dent->d_name;

		if(strcmp(name_file, target_file) == 0){
			printf("file exsits!\n");
			closedir(dp);
			return 0;
		}
	}

	printf("file isn't here.\n");
	closedir(dp);
	return 0;
}

