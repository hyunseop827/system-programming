/*
 * CLA, printf UID and permission.
 *
 */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void stat_per(mode_t mode, char out[10]){
    out[0] = (mode & S_IRUSR) ? 'r' : '-';
    out[1] = (mode & S_IWUSR) ? 'w' : '-';
    out[2] = (mode & S_IXUSR) ? 'x' : '-';
    out[3] = (mode & S_IRGRP) ? 'r' : '-';
    out[4] = (mode & S_IWGRP) ? 'w' : '-';
    out[5] = (mode & S_IXGRP) ? 'x' : '-';
    out[6] = (mode & S_IROTH) ? 'r' : '-';
    out[7] = (mode & S_IWOTH) ? 'w' : '-';
    out[8] = (mode & S_IXOTH) ? 'x' : '-';
    out[9] = '\0';
}


int main (int argc, char *argv[]){

	int n = argc;

	if (n != 2){
		printf("only 1 arguemtn is required");
		exit(1);
	}


	struct stat statbuf;
	char* name = argv[1];

	stat(name, &statbuf);

	int gid = (int)statbuf.st_gid;
	char p[10];

	stat_per(statbuf.st_mode, p);

	printf("%s %d %s\n",name, gid, p);

	return 0;
}

