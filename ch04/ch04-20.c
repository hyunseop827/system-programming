/*
 * tmpnam
 *
 * make temp file by system.
 * without argument system decide the name of temp file.
 * with arguemt, make temp file on where argument points.
 *
 * #include <stdio.h>
 *
 * char *tmpnam(char *s);
 *
 * s: address of buffer
 *
 */

/*
 * mktemp
 *
 * make temp file with template.
 *
 * #include <stdlib.h>
 *
 * char *mktemp(char *template);
 *
 * template: template of temp.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *fname;
	char fntmp[BUFSIZ];
	char template[32];

	fname = tmpnam(NULL);
	printf("1. tmp file name(tmpnam): %s\n",fname);

	tmpnam(fntmp);
	printf("2. tmp file name(tmpnam): %s\n",fntmp);

	strcpy(template, "/tmp/systemXXXXXX");
	fname =mktemp(template);
	printf("3. tmp file name(mktemp): %s\n",fname);

	return 0;
}

