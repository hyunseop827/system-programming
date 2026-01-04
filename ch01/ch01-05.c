/*
 * strerror fucntion.
 *
 * included since ANSI C, argument is errno.
 * The function read errno, and returns error message as string.
 * programmer can process the string.
 *
 * #include <string.h>
 *
 * char *strerror(int errnum);
 *
 * errnum: value of errno.
 */
 
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main() {
	char *err;

	if(access ("test.txt", R_OK ) == -1){
		err = strerror(errno);
		printf("ERROR = %s(test.txt)\n", err);
		exit(1);
	}
}

