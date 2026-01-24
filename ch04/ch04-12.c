/*
 * gets, fgets
 *
 * #include <stdio.h>
 *
 * char *gets(const char *s);
 * char *fgets(char *s, int size, FILE *stream);
 *
 * s: start address of buffer for string.
 * size: size of buffer.
 * stream: file pointer
 *
 * >> gets read string from standard input, till `enter` or `EOF`, without `\n`, and add `\0`. However `gets` can read until s is fully allocated, it's not recommanded.
 * >> fgets read string as size - 1. while it's reading, if it's `\n` or `EOF` then it stops. unlikely `gets`, `fgets` also read `\n` and allocates it at string with `\0`.
 * >> all of them, when they reach `EOF` then they return NULL, if it's successful, then it returns start address of `s`.
 *
 */

/*
 * puts, fputs 
 *
 * #include <stdio.h>
 *
 * int puts(const char *s);
 * int fputs(const char *s, FILE *stream);
 *
 * s: address of string.
 * stream: file pointer.
 *
 * >> puts print string (`s`) as standard output with `\n`
 * >> fputs print string (`s`) as standard output on file, it doesn't add `\n`
 * >> both returns positive number when it's successed, if it's `EOF` then returns error.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *rfp, *wfp;
	char buf[BUFSIZ];

	if ((rfp = fopen("linux.txt", "r")) == NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	if ((wfp = fopen("linux.out","a")) == NULL){
		perror("fopen: linux.out");
		exit(1);
	}

	while ((fgets(buf, BUFSIZ, rfp) != NULL)){
		fputs(buf,wfp);
	}

	fclose(wfp);
	fclose(rfp);

	return 0;
}

