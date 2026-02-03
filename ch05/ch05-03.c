/*
 * fpathconf/pathconf
 *
 * fpathconf uses `file descriptor` and returns resource or option values.
 * pathconf uses path and returns resource or option values.
 *
 * these returns integer when it's success, else returns -1.
 * 
 * #include <unistd.h>
 * 
 * long fpathconf(int fd, int name);
 * long pathconf(const char *path, int name);
 *
 * fd: file descriptor.
 * path: path of directory or file.
 * name: constants to assign informations to be searched.
 */

#include <unistd.h>
#include <stdio.h>

int main() {
	printf("link max: %ld\n", pathconf(".",_PC_LINK_MAX));
	printf("name max: %ld\n", pathconf(".",_PC_NAME_MAX));
	printf("path max: %ld\n", pathconf(".",_PC_PATH_MAX));

	return 0;
}

