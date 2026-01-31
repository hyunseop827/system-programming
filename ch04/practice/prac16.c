/*
 * making temp file and print name of file.
 * fprtinf id and name of students
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	char template[] = "/tmp/student_XXXXXX";

	int fd = mkstemp(template);
	if (fd == -1) {
		perror("mkstemp");
		return 1;
	}

	printf("Temporary file name: %s\n", template);

	FILE *fp = fdopen(fd, "w");
	if (fp == NULL) {
		perror("fdopen");
		close(fd);          
		return 1;
	}

	int student_id = 2020202020;
	char *student_name = "Hyunseop";

	fprintf(fp, "%d %s\n", student_id, student_name);

	fclose(fp);

	return 0;
}

