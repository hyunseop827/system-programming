/*
 * using atexit(), print directory list before program exit.
 *
 */

#include <stdio.h>
#include <stdlib.h>

void print_directory() {
	system("ls -l");
}

int main() {
	printf("start of program\n");

	atexit(print_directory);

	printf("end of program\n");

	return 0;
}

