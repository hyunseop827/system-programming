/*
 * read `data.txt` and print average with id in high-level IO.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE *rfp, *wfp;

	if ((rfp = fopen("data.txt", "r")) == NULL){
		perror("fopen: data.txt");
		exit(1);
	}

	
	printf("id	avg\n");

	// get rid of first row.
	char trash[BUFSIZ];
	fgets(trash, sizeof(trash), rfp);

	int id, s1, s2, s3;
	int n;
	while((n = fscanf(rfp, "%d %d %d %d", &id, &s1, &s2, &s3)) != EOF){
		printf("%d	%d\n",id, (s1+s2+s3)/3);
	}

	fclose(rfp);

	return 0;
}

