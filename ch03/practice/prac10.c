/*
 * print every files and directories name and inode
 *
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

void list_print(const char *path, int depth){

	DIR *dp = opendir(path);
	if(dp == NULL) return;

	struct dirent *dent;

	while((dent = readdir(dp))){
		char* checking = dent->d_name;

		for (int i = 0; i < depth; i++) printf("-");
		printf("name: %s, inode: %lu\n", dent->d_name, (unsigned long)dent->d_ino);

		if (((dent->d_type == DT_DIR) && ((strcmp(checking,".") != 0)&& (strcmp(checking,"..") != 0)))){
			char new_path[BUFSIZ];
			snprintf(new_path, sizeof(new_path), "%s/%s", path, dent->d_name);
			list_print(new_path, depth+1);
		}
	}
	
	closedir(dp);
}



int main(){
	list_print(".", 0);
	return 0;
}

