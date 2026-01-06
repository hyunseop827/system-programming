/*
 * write code which check if directory is empty or no.
 * if it is empty print, that it's empty.
 * and delete that empty directory.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(){

	// declare variables.
	DIR *dp;
	struct dirent *dent;
	char *dir_name;

	dp = opendir(".");

	while((dent = readdir(dp))){
		dir_name = dent->d_name;
		if(strcmp(dir_name,".") == 0 || strcmp(dir_name,"..") == 0)
			continue;

		if(rmdir(dir_name) == -1){
			printf("%s isn't empty!\n",dir_name);
			continue;
		}
		else{
			printf("%s was empty, it's deleted now!\n",dir_name);
		}
	}

	closedir(dp);

	return 0;
}

