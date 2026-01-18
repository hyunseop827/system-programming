/*
 * write program that moves to certian directory
 *
 */


#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]) {

	if (argc != 3){
		printf("error\n");
		exit(1);
	}

	char* src = argv[1];
	char* new = argv[2];

	char s[4000];

	snprintf(s,sizeof(s),"%s/%s",new,src);

	if(rename(src,s) == -1){
		perror("rename");
		exit(1);
	}
}
