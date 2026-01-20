/*
 * lseek
 *
 * + and - can be used, it's for direction.
 * returns offset if it successes, else returns -1
 *
 * off_t is written in `sys/types.h` as `long`
 *
 * #include <sys/type.h>
 * #include <unistd.h>
 * 
 * off_t lseek(int fd, off_t offset, int whence);
 *
 * fd: file discripter
 * offset: offest to move
 * whence: offset for standard
 *
 */

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int fd, n;
	off_t start, cur;
	char buf[256];

	fd = open("linux.txt", O_RDONLY);
	if (fd == -1){
		perror("open linux.txt");
		exit(1);
	}

	start = lseek(fd,0,SEEK_CUR);
	n = read(fd,buf,255);

	buf[n] = '\0';

	printf("offset start=%d, n=%d, read str=%s", (int)start, n, buf);
	
	cur = lseek(fd,0,SEEK_CUR);
	printf("offset cur=%d\n",(int)cur);

	start = lseek(fd, 6, SEEK_SET);
	n = read(fd,buf,255);

	buf[n] = '\0';
	printf("offset start=%d, n=%d, read str=%s", (int)start, n, buf);

	close(fd);
}

