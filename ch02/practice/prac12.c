/*
 * without `.`, `..`
 * write to print ls.
 *
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

//function to check if it's directory
void list_dir(const char *path, int depth){

	DIR *dp = opendir(path);
	if(dp == NULL){
		return;
	}

	struct dirent *dent;

	while ((dent = readdir(dp)) != NULL){
		char* dir_name = dent->d_name;

		if(strcmp(dir_name, ".") == 0 || strcmp(dir_name, "..") == 0)
			continue;
		
		//print out..
		for(int i = 0 ; i < depth; i++) printf("--");
		printf("%s\n",dir_name);

		if (dent->d_type == DT_DIR) {
		    	char new_path[BUFSIZ];
			snprintf(new_path, sizeof(new_path), "%s/%s", path, dir_name);
			list_dir(new_path, depth + 1);
		}

	}
	closedir(dp);
}

int main() {
	list_dir(".", 0);
	return 0;
}

