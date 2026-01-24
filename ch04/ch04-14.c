/*
 * fwrite
 *
 * `fwrite` read size of data as many as `nmemb` from `ptr` and print out to `stream`
 * returns a number of items that has been printed when it's succcessed, else return `EOF` when it's failed.
 *
 * #include <stdio.h>
 *
 * size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
 *
 * ptr: address of buffer.
 * size: size of item.
 * nmemb: a number of item.
 * stream: file pointer.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *rfp, *wfp;
	char buf[BUFSIZ];
	int n;

	if ((rfp = fopen("linux.txt", "r")) == NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	if ((wfp = fopen("linux.out","a")) == NULL){
		perror("fopen: linux.out");
		exit(1);
	}

	while ((n = fread(buf, sizeof(char)*2, 4, rfp)) > 0){
		fwrite(buf, sizeof(char)*2, n, wfp);
	}
	
	fclose(rfp);
	fclose(wfp);
	
	return 0;
}

