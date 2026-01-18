/*
 * check error msg,
 * when you try to make hardlink in other file system
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {

	link("../linux.txt", "/dev/shm/linux.ln");	
	perror("link");

	return 0;
}

