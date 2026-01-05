/*
 * telldir/seekdir/rewinddir
 *
 * when you open directory and read, the stream of directory: offset,  where points out current location moves.
 * to read location of offest and move offest 
 * fuction `telldir()`, `seekdir()`, `rewinddir()` 
 *
 * #include <sys/types.h>
 * Einclude <dirent.h>
 *
 * long telldir(DIR *dirp);
 * void seekdir(DIR *dirp, long loc);
 * void rewinddir(DIR *dirp);
 *
 * telldir() returns location of directory stream where argument points.
 * returns -1 when fails.
 *
 * seekdir() move offset where readdir() can read next.
 * loc argument should be value of telldir's return.
 *
 * rewinddir() moves directory stream to starting point.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {

	DIR *dp;
	struct dirent *dent;
	long loc;

	// open current directory.
	dp = opendir(".");

	printf("Start point: %ld\n", telldir(dp));

	while ((dent = readdir(dp))) {
		printf("Read: %s -> ", dent->d_name);
		printf("Current Position: %ld\n", telldir(dp));
	}

	printf("** directory position rewind **\n");
	rewinddir(dp);
	printf("current position: %ld\n", telldir(dp));
	
	printf("** move directory pointer **\n");
	readdir(dp);
	loc = telldir(dp);
	seekdir(dp,loc);
	printf("current position: %ld\n", telldir(dp));

	dent = readdir(dp);
	printf("read: %s \n", dent->d_name);

	closedir(dp);
}

