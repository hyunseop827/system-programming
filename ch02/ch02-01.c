/**
 * mkdir fuction
 *
 * #include <sys/stat.h>
 * #include <sys/types.h>
 *
 * int mkdir(const char *pathname, mode_t mode);
 *
 * pathname : path where directory is in.
 * mode : authority number (755, 655 etc..);
 */

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	if (mkdir("han", 0755) == -1){
		perror("han");
		exit(1);
	}
}
