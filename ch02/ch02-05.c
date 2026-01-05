/*
 * rename
 *
 * change directory name.
 *
 * #include <stdlib.h>
 *
 * int rename(const char *oldpath, const char *newpath);
 *
 * oldpath: old directory/file
 * newpaht: new directory/file
 *
 * it deletes if second parameter exsits.
 * if error occurs, old and new one exist.
 * returns 0 if it successes, else returns -1.
 *
 */

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	if (rename ("han", "bit") == - 1){
		perror("rename");
		exit(1);
	}
}

