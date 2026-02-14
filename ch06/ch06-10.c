/*
 * setenv
 *
 * setenv also changes env like `putenv()`.
 * it gets value and argument also, the flag for overwriting.
 * if overwrite isn't 0 then it overwrite. else doesn't.
 *
 * #include <stdlib.h>
 *
 * int setenv(const char *name, const char *value, int overwrite);
 *
 * name: name of argument.
 * value: value.
 * overwrite: overwrite.
 *
 */

/*
 * unsetenv
 *
 * deletes name from env. if it doesn't exsit, it changes nothing.
 *
 * #include <stdlib.h>
 *
 * int unsetenv(const char *name);
 * 
 * name: name of env.
 *
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

	setenv("TERM", "vt100", 0);

	val = getenv("TERM");

	printf("2. TERM = %s\n", val);

	setenv("TERM","vt100",1);

	val = getenv("TERM");
	printf("3. TERM = %s\n", val);

	return 0;
}

