/*
 * putenv
 *
 * set env. `ARG=VALUE`
 * it returns original ones and allocates memory for new one.
 * it returns 0 when it's successful.
 *
 * #include <stdlib.h>
 *
 * int putenv(char *string);
 */

#include <stdlib.h>
#include <stdio.h>

int main() {

	char *val;

	val = getenv("TERM");

	if (val == NULL)
		printf("TERM not defined\n");
	else
		printf("1. TERM = %s\n", val);

	putenv("TERM=vt100");

	val = getenv("TERM");

	printf("2. TERM = %s\n", val);

	return 0;
}

