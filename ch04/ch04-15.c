/*
 * scanf, fscanf
 *
 * they return a number of item they read.
 * if input is not compatiable with format, returns 0.
 * if it read end of file, returns `EOF`
 *
 * #include <stdio.h>
 *
 * int scanf(const char *format, ...);
 * int fscnaf(FILE *stream, const char *format, ...);
 *
 * format: input format (%s, %d ...)
 * stream: file pointer
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *rfp;
	int id, s1, s2, s3, s4, n;

	if ((rfp = fopen("linux.dat","r")) == NULL ){
		perror("fopen: linux.dat");
		exit(1);
	}

	printf("id	average\n");
	while ((n = fscanf(rfp, "%d %d %d %d %d", &id, &s1, &s2, &s3, &s4)) != EOF){
		printf("%d: %d\n",id, (s1+s2+s3+s4)/4);
	}
	
	fclose(rfp);

	return 0;
}

