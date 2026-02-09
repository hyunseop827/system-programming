/*
 * print host name from `uname()` and `gethostname()` 
 * and see the differencies.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

int main() {

	// uname
	
	struct utsname uts;
	if(uname(&uts) == -1){
		perror("uname");
		exit(1);
	}


	// gethostname
	char host_name[255];
	if(gethostname(host_name, sizeof(host_name)) == -1){
			perror("gethostname");
			exit(1);
	}

	printf("uname\n");
	printf("%s\n", uts.nodename);

	printf("------------------\n");

	printf("gethostname\n");
	printf("%s\n", host_name);

	return 0;
}



				
