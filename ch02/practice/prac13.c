/*
 * print all list of current directory
 * and use seekdir() to change stream's location.
 * print 3rd file's name
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main() {

	DIR *dp;
	struct dirent *dent;

	// print all 
	dp = opendir(".");
	
	while ((dent = readdir(dp))){
		printf("name: %s\n", dent->d_name);
		printf("I-node: %d\n",(int)dent->d_ino);
	}

	// goes to starting point
	rewinddir(dp);

	// goes to 3rd one.

	for(int i = 0; i < 2; i++){
		if(readdir(dp) == NULL){
			perror("readir");
			exit(1);
		}
	}

	long loc = telldir(dp);	

	seekdir(dp, loc);

	//read dir
	dent = readdir(dp);
	
	printf("Read: %s\n", dent->d_name);

	return 0;
}

