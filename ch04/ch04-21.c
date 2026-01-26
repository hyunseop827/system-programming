/*
 * `tmpnam()`, `mktemp()` only make name of temp file.
 * to IO with temp files, need to open file.
 *
 * tmpfile, mkstemp
 *
 * these allow programmer to open file with discriptor and pointer.
 *
 * #include <stdio.h>
 *
 * FILE *tmpfile();
 *
 * #include <stdlib.h>
 *
 * int mkstemp(char *template);
 *
 * template: template
 *
 * >> tmpfile() only returns file pointer with `w+` mode.
 * >> mkstemp() returns file discripter, samely used as `mktemp()`
 *
 */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *fp;
	int fd;
	char template[32];
	int ret;


	fp = tmpfile();
	fputs("temp file", fp);
	fclose(fp);

	strcpy(template, "/tmp/systemXXXXXX");
	fd = mkstemp(template);

	write(fd, "temp file", 10);
	close(fd);

	return 0;
}

