/*
 * opendir
 *
 * open directory
 *
 * makes stream and returns pointer of stream.
 * when it's successed, it returns DIR object.
 *
 * DIR object has directory's data, written in dirent.h as typedef struct ~ dirstream DIR.
 * user can't know detail of direstream struct, it's controlled by system only.
 * when it's failed, it returns NULL
 *
 * #include <sys/types.h>
 * #include <dirent.h>
 *
 * DIR *opendir(const char *name);
 *
 * name: name of directory.
 */

/*
 * closedir
 *
 * close directory.
 * returns 0, when it's successed. else return -1;
 *
 * #include <sys/types.h>
 * #include <dirent.h>
 *
 * int closedir(DIR *dirp);
 * 
 * dirp: pointer of directory.
 */

/*
 * readdir
 *
 * read directory.
 *
 * read directory in order, returns NULL when it's end.
 *
 * returns pointer of dirent struct.
 * dirent is defined in sys/dirent.h
 *
 * strct dirent {
 * 	ino_t d_ino; // inode number
 * 	off_t d_off; // direct0ry offset location.
 * 	unsigned short d_reclen; // length of records.
 * 	unsigned char d_type; // type of file
 * 	char d_name[256]; // name of file
 * }
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
	DIR *dp;
	struct dirent *dent;

	dp = opendir(".");

	while ((dent = readdir(dp))) {
		printf("name: %s\n", dent->d_name);
		printf("inode: %d\n",(int)dent->d_ino);
	}

	closedir(dp);
}

