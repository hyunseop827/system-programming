/*
 * read
 *
 * read `count` byte and save it at buf.
 * return -1 when it's failed. if it's 0 then it's EOF.
 * only read as byte.
 * `ssize_t` is written in `<sys/types.h>` as `int` (or `long` in certian distro)
 *
 * #include <unistd.h>
 *
 * ssize_t read(int fd, void *buf, size_t count);
 *
 * fd: file discripter
 * buf: memory
 * count: size of buf
 *
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int fd, n;
	char buf[10];

	fd = open("linux.txt", O_RDONLY);
	if (fd == -1){
		perror("open");
		exit(1);
	}

	n = read(fd, buf, 5);

	if(n == -1){
		perror("read");
		exit(1);
	}

	buf[n] = '\0';
	printf("n =%d, buf =%s\n",n,buf);
	close(fd);
}

