/*
 * get name of directory with CLA
 * and check if it's in here.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]){

	int n = argc;

	if(n <= 1){
		printf("not enough argument.\n");
		return 0;
	}

	char *target = argv[1];
	DIR *dp;
	struct dirent *dent;

	dp = opendir(".");
	if(dp == NULL){
		perror("opendir");
		return 1;
	}

	while((dent = readdir(dp))){
		char *name = dent->d_name;

		if(strcmp(name, target) == 0){
			printf("%s is in this directory!\n",target);
			return 0;
		}
	}

	printf("%s isn't in this directory!\n",target);

	closedir(dp);
	return 0;
}

	
