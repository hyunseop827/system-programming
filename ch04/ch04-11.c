/*
 * fopen
 *
 * return file pointer. (high-level file IO)
 *
 * #include <stdio.h>
 *
 * FILE *fopen(const char *pathname, const char *mode);
 *
 * pathname: path of file
 * mode: mode to open file
 */

/*
 * fclose
 *
 * to close file
 * returns 0 (succesful), `EOF (-1)` when it's failed.
 *
 * #include <stdio.h>
 *
 * int fclose(FILE *stream);
 *
 * stream: pointer that returned.
 */

/*
 * fgetc, getc, getchar, getw
 *
 * read byte from file.
 * return EOF if it's failed.
 * it returns int not char beacuse of overflow when it's 1111 1111.
 *
 * #include <stdio.h>
 *
 * int fgetc(FILE *stream);
 * int getc(FILE *stream);
 * int getchar(void);
 * int getw(FILE *stream);
 *
 * stream: file pointer.
 *
 * >> fgetc reads one charator as `unsigned char` from a file.
 * >> getc is written as macro, could be faster but allocates more memory. besides this, works same as fgetc.
 * >> getchar is a macro that reads one charator from standard input. it's same as getc(stdin).
 * >> getw reads files as `word` unit. word's size is same as int. could be different by system.
 *
 */

/*
 * fputc, putc, putchar, putw
 *
 * write byte to file.
 * returns value of charater when it's successed, else EOF.
 *
 * #include <stdio.h>
 *
 * int fputc(int c, FILE *stream);
 * int putc(int c, FILE *stream);
 * int putchar(int c);
 * int putw(int w, FILE *stream);
 *
 * c, w: char to print.
 * stream: file pointer.
 *
 * >> fputc converts int data `c` to `unsigned int` and print on file.
 * >> putc works same as fputc, is implemented as macro.
 * >> putchar is macro to print one charater to standard output. same as `putc(c,stdout)`
 * >> putw print data on files as `word` unit, size is same as int's.
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *rfp, *wfp;
	int c;

	if ((rfp = fopen("linux.txt", "r")) == NULL){
		perror("fopen: linux.txt");
		exit(1);
	}

	if ((wfp = fopen("linux.out","w")) == NULL){
		perror("fopen: linux.out");
		exit(1);
	}

	while ((c = fgetc(rfp)) != EOF){
		fputc(c,wfp);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}

