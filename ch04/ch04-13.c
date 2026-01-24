/*
 * fread
 *
 * `fread` read size of data as many as `nmemb` and allocated in buffer which is referred by ptr.
 * return number of `nmemb` when it is successful, else it returns 0, and `EOF` at the end of file.
 *
 * #include <stdio.h>
 *
 * size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
 *
 * ptr: address of buffer
 * size: size of buffer
 * nmemb: a number of items
 * stream: file pointer
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *rfp;
	char buf[BUFSIZ];
	int n;

	if ((rfp = fopen("linux.txt", "r")) == NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	while ((n=fread(buf, sizeof(char)*2, 4, rfp)) > 0){
		buf[8] = '\0';
		printf("n = %d, buf = %s\n", n, buf);
	}

	fclose(rfp);

	return 0;
}

