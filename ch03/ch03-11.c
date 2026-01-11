/*
 * realink
 *
 * to read symbolic link's data
 * if it success, returns size of data blocks, else return -1.
 *
 * #include <unistd.h>
 *
 * ssize_t readlink(const char *pathname, char *buf, size_t bufsize);
 *
 * pathname: symbolic link's path
 * buf: buffer to store data
 * bufsize: size of buffer
 *
 */

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	char buf[BUFSIZ];
	int n;

	n = readlink("linux.sym", buf, BUFSIZ);

	if (n == -1){
		perror("readlink");
		exit(1);
	}

	buf[n] = '\0';

	printf("linux.sym: READLINK= %s\n",buf);
}

