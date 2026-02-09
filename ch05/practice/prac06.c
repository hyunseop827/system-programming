/*
 * using `usname()`, write myuname
 * option
 * -a: all info
 * -k: kernel realease
 * -r: kernel number
 * -n: host name
 * -h: hardware name
 * -s: os name
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

// check options and print out.
void print_option(char n, struct utsname *uts) {
	switch(n){
		case 'a':
			printf("OS name: %s\n", uts->sysname);
			printf("Node name: %s\n", uts->nodename);
			printf("Release: %s\n", uts->release);
			printf("Version: %s\n", uts->version);
			printf("Machine: %s\n", uts->machine);
			break;

		case 'k':
			printf("Relase: %s\n", uts->release);
			break;
		case 'r':
			printf("Version: %s\n", uts->version);
			break;
		case 'n':
			printf("Node name: %s\n", uts->nodename);
			break;
		case 'h':
			printf("Machine: %s\n", uts->machine);
			break;
		case 's':
			printf("OS name: %s\n", uts->sysname);
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

	struct utsname uts;

	if(uname(&uts) == -1){
		perror("uname");
		exit(1);
	}

	char n;
	while((n = getopt(argc, argv, "akrnhs")) != -1){
		print_option(n, &uts);
	}

	return 0;
}

