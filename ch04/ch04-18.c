/*
 * low-level file IO -> file discriptor
 * high-level file IO -> file pointer
 *
 * to convert...
 * file discriptor -> file pointer: FILE *fdopen(int fd, const char *mode);
 * file pointer -> file discriptor: int filen(FILE *stream);
 *
 */

/*
 * fdopen
 *
 * it returns file pointer
 * mode can be used constants which used in `fopen()`
 * it has to be same mode which used in `fopen()`
 * it returns file pointer if it was successful
 * else, returns `NULL`
 *
 * #include <stdio.h>
 *
 * FILE *fdopen(int fd, const char *mode);
 *
 * fd: file discriptor
 * mode: mode
 *
 */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *fp;
	int fd;
	char str[BUFSIZ];

	fd = open("linux.txt", O_RDONLY);

	if (fd == -1){
		perror("open");
		exit(1);
	}

	fp = fdopen(fd, "r");

	fgets(str, BUFSIZ, fp);
	printf("read: %s\n",str);

	fclose(fp);

	return 0;
}

