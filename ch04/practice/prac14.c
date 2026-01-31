/*
 * using high-level, write code to change name of file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	if (argc != 3){
		printf("2 arguments required\n");
		exit(1);
	}


	char *from = argv[1];
	char *to = argv[2];

	// open file 
	FILE *rfp, *wfp;
	char buf[BUFSIZ];

	if ((rfp = fopen(from,"r")) == NULL){
		perror("fopen");
		exit(1);
	}

	if ((wfp = fopen(to, "w")) == NULL){
		perror("fopen");
		exit(1);
	}

	while (fgets(buf, BUFSIZ, rfp) != NULL){
		fputs(buf, wfp);
	}

	fclose(rfp); fclose(wfp);

	//delete old one.
	unlink(from);

	return 0;
}

