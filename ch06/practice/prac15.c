/*
 * using `setenv()` to define `TESTENV` as `ubuntu` and use `getenv()` to print out.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	char *val;

	setenv("TESTENV","ubuntu",0);

	val = getenv("TESTENV");

	printf("TESTENV = %s\n", val);

	return 0;
}

