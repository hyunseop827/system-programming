/*
 * use rmdir, and see what happens when you try to delete
 * directory which is not exist.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	//delete random folder
	if(rmdir("nonexists") == -1){
		perror("rmdir");
		exit(1);
	}
}

