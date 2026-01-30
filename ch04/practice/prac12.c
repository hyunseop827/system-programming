/*
 * re write prac10 using fwrite() and fread();
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	if (argc != 2){
		printf("1 argument required\n");
		exit(1);
	}

	char *file = argv[1];
	FILE *fp;

	if((fp=fopen(file,"r")) == NULL){
		perror("fopen");
		exit(1);
	}

	int n;
	char buf[BUFSIZ];
	while((n = fread(buf,sizeof(char),1,fp)) > 0){
		fwrite(buf,sizeof(char),1,stdout);
		fseek(fp,1,SEEK_CUR);
	}

	return 0;
}

