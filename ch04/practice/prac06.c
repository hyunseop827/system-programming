/*
 * using low-level, write `newcat`
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("only one arguemnt required\n");
		exit(1);
	}

	// open file with descriptor.
	char* fileName = argv[1];
	int fd;

	fd = open(fileName,O_RDONLY);

	if(fd == -1){
		perror("open");
		exit(1);
	}

	printf("%s is opened\n",fileName);

	int n;
	int rowNo = 1;
	int index = 0;

	char buf;
	char row[BUFSIZ];

	// read and print with numbers.

		// add 1 byte in buffer.
	while((n = read(fd, &buf, 1)) == 1){
		row[index++] = buf;
		if (buf == '\n'){
			row[index] = '\0';
			printf("%d: %s",rowNo, row);
			index = 0;
			rowNo++;
		}
	}

	close(fd);

	return 0;
}

