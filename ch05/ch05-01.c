/*
 * uname
 *
 * search OS information.
 * returns 0 when it's successful, else -1.
 * it saves data in utsname struct.
 * utsname struct is written in `sys/utsname.h`
 *
 * #include <sys/utsname.h>
 * 
 * int uname(struct utsname *buf);
 *
 * buf: utsname struct address.
 */

/*
 * strcut utsname {
 * 	char sysname[];
 * 	char nodename[];
 * 	char release[];
 * 	char version[];
 * 	char machine[];
 * };
 *
 * sysname: name of OS.
 * nodename: name of system for networking.
 * release: release number of OS.
 * version: version of OS.
 * machine: name of hardware on currently OS.
 */

#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	struct utsname uts;

	if (uname(&uts) == -1){
		perror("uname");
		exit(1);
	}

	printf("OS name: %s\n", uts.sysname);
	printf("Node name: %s\n", uts.nodename);
	printf("Release: %s\n", uts.release);
	printf("Versionn: %s\n", uts.version);
	printf("Machine: %s\n", uts.machine);

	return 0;
}

