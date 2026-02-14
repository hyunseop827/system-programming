/*
 * getenv
 *
 * return whether the argument is set as env or not.
 * returns NULL when it's failed.
 *
 * #include <stdlib.h>
 *
 * char *getenv(const char *name);
 *
 * name: name of env.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char *val;

	val = getenv("SHELL");

	if (val == NULL) printf("SHELL inot defined\n");

	else printf("SHELL = %s\n",val);

	return 0;
}

