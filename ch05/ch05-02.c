/*
 * sysconf
 *
 * in Linux, it limits maxs of resources each hardware can use.
 * these are written in `limits.h` which is POSIX standard.
 *
 * returns system's resource or option value if it's successful.
 * else returns -1.
 *
 * #include <unistd.h>
 *
 * long sysconf(int name);
 *
 * name: constant to search up.
 */

#include <unistd.h>
#include <stdio.h>

int main() {
	printf("arg max: %ld\n", sysconf(_SC_ARG_MAX));
	printf("clock tick: %ld\n", sysconf(_SC_CLK_TCK));
	printf("max open file: %ld\n", sysconf(_SC_OPEN_MAX));
	printf("max login name length: %ld\n", sysconf(_SC_LOGIN_NAME_MAX));

	return 0;
}

