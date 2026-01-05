/*
 * get_current_dir_name
 *
 * returns absoulte path.
 *
 * #include <unistd.h>
 *
 * char *get_current_dir_name(void);
 *
 * system allocates memory and returns it.
 * same as getcwd(NULL,0);
 *
 * needs to write `_GUN_SOURCE`
 */

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

	char *cwd;

	cwd = get_current_dir_name();
	printf("cwd = %s\n",cwd);
	free(cwd);
}

