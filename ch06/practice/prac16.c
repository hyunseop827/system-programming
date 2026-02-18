/*
 * modify prac15, to delete `TESTENV`
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

	char *val;

	val = getenv("TESTENV");

	if(val == NULL)
		printf("TESTENV is not defined\n");
	else{
		printf("TESTENV = %s\n", val);
		printf("unset TESTENV\n");

		unsetenv("TESTENV");
	}
}

