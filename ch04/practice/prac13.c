/*
 * using `fgetc()` to check if certain charater is in the file.
 */

#include <stdio.h>
#include <stdlib.h>

int main () {

	char target;
	char file[BUFSIZ];

	printf("what charater? :");
	scanf("%c", &target);

	printf("name of file? :");
	scanf("%s", file);

	
	FILE *rfp;
	int c;
	//opening file.
	
	if ((rfp = fopen(file, "r")) == NULL){
		perror("fopen");
		exit(1);
	}

	int count = 0;
	while ((c = fgetc(rfp)) != EOF){
		if(c == target){
			count++;
		}
	}

	if(count){
		printf("%c is in file: %s, for %d times\n",target, file, count);
	}
	else{
		printf("%c is not in the file: %s\n",target, file);
	}

	fclose(rfp);

	return 0;
}

