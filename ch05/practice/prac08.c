/*
 * using `sysconf` and write your own `mysys`
 *
 * option
 *
 * -a: all infos
 * -h: max host name length
 * -p: max process
 * -l: max login name length
 * -x: POSIX version
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_option(char n) {
	switch(n){
		case 'a':
			printf("Max host name: %ld\n", sysconf(_SC_VERSION));
			printf("Max proccess: %ld\n", sysconf(_SC_CHILD_MAX));
			printf("Max login name length: %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
			printf("POSIX version: %ld\n", sysconf(_SC_VERSION));
			break;

		case 'h':
			printf("Max host name: %ld\n", sysconf(_SC_VERSION));
			break;

		case 'p':
			printf("Max proccess: %ld\n", sysconf(_SC_CHILD_MAX));
			break;

		case 'l':
			printf("Max login name length: %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
			break;

		case 'x':
			printf("POSIX version: %ld\n", sysconf(_SC_VERSION));
			break;

		default:
			perror("unknown option");
			exit(1);
			break;

	}
}

int main(int argc, char *argv[]) {

	extern char *optarg;
	extern int optind;

	char n;
	while((n = getopt(argc, argv, "ahplx")) != -1){
		print_option(n);
	}

	return 0;
}


