/*
 * rmdir fuction.
 * 
 * delete directory.
 * return 0 if it's successed, else return -1
 *
 * #include <unistd.h>
 *
 * int rmdir(const char* pathname);
 *
 * pathname: name of directory.
 *
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	if (rmdir("han") == -1){
		perror("han");
		exit(1);
	}
}

