/*
 * using `putenv()`, CLA change SHELL.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	char* target = argv[1];

	char* val;

	val = getenv("SHELL");

	if(val == NULL) printf("SHELL not defined\n");
	else printf("1. SHELL = %s\n", val);

	
	char out[256];
	snprintf(out, sizeof(out), "%s=%s", "SHELL", target);

	putenv(out);

	val = getenv("SHELL");
	printf("2. SHELL = %s\n", val);

	return 0;
}

