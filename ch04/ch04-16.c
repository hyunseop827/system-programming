/*
 * printf, fprintf
 *
 * they returns charater as success, else return `EOF` as failure.
 *
 * #include <stdio.h>
 *
 * int printf(const char *format, ...);
 * int fprintf(FILE *stream, const char *format, ...);
 *
 * stream: file pointer
 * format: format
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *rfp, *wfp;
	int id, s1, s2, s3, s4, n;

	if ((rfp = fopen("linux.dat", "r")) == NULL){
		perror("linux.dat");
		exit(1);
	}

	if ((wfp = fopen("linux.scr", "w")) == NULL){
		perror("linux.scr");
		exit(1);
	}

	fprintf(wfp, "id	avg\n");
	while ((n=fscanf(rfp, "%d %d %d %d %d", &id, &s1, &s2, &s3, &s4)) != EOF){
		fprintf(wfp, "%d: %d\n", id, (s1+s2+s3+s4)/4);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}

