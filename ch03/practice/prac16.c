/*
 * CLA, link create and printf it out.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]) {

	if(argc != 2){
		printf("error\n");
		exit(1);
	}

	char* src = argv[1];
	char buf[200];
	snprintf(buf, sizeof(buf),"%s.sym",src);
	symlink(src,buf);

	struct stat statbuf;

	char buff[BUFSIZ];
	int n;

	n = readlink(buf,buff,BUFSIZ);

	buff[n] = '\0';
	printf("%s: READLINK= %s\n",buf,buff);

	printf("original path= %s\n", src);
}


