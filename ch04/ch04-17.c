/*
 * fseek
 *
 * move offset on stream.
 * whenece is constant,
 * SEEK_SET: start of file
 * SEEK_CUR: current position
 * SEEK_END: end of file
 *
 * function returns 0 when it's successed, else `EOF`
 *
 * #include <stdio.h>
 * 
 * int fseek(FILE *stream, long offset, int whence);
 *
 * stream: file pointer
 * offset: offset
 * whence: standard
 *
 */

/*
 * ftell
 *
 * ftell returns offset of current file.
 * it returns a number of byte from the start of file.
 * it returns `EOF` when it's failed.
 *
 * #include <stdio.h>
 *
 * long ftell(FILE *stream);
 *
 */

/*
 * rewind
 *
 * move offset to the start position.
 *
 * #include <stdio.h>
 *
 * void rewind(FILE *stream);
 *
 * stream: file pointer
 *
 */

/*
 * fflush
 *
 * flush date on buffer to disk
 * if file was opened as read only, then clear buffer.
 *
 * #include <stdio.h>
 *
 * int fflush(FILE *stream);
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *fp;
	int n;
	long cur;
	char buf[BUFSIZ];

	if ((fp = fopen("linux.txt", "r")) == NULL){
		perror("linux.txt");
		exit(1);
	}

	cur = ftell(fp);
	printf("offset cur=%d\n",(int)cur);

	n = fread(buf, sizeof(char), 5, fp);
	buf[n] = '\0';
	printf("-- read str=%s\n",buf);

	fseek(fp,1,SEEK_CUR);

	cur = ftell(fp);
	printf("offset cur=%d\n",(int)cur);

	n = fread(buf, sizeof(char), 6, fp);
	buf[n] = '\0';
	printf("-- read str=%s\n",buf);

	fseek(fp, 1, SEEK_CUR);

	cur = ftell(fp);
	printf("offset cur=%d\n",(int)cur);

	n = fread(buf, sizeof(char), 11, fp);
	buf[n] = '\0';

	printf("-- read str=%s\n",buf);

	rewind(fp);
	cur = ftell(fp);
	printf("rewind offset cur=%d\n",(int)cur);

	fclose(fp);

	return 0;
}

