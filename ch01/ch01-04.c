/*
 * perror function.
 * 
 * print standard error message, read from errno.
 * argument will be printed as <arguments> : <error message>
 *
 * #include <stdio.h>
 *
 * void perror(const char*s);
 *
 * s: string to print out.
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main() {
	if(access("test.txt", R_OK) == -1){
		perror("test.txt");
		exit(1);
	}
}

